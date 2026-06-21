#include <stdio.h>
#include <pthread.h>

int buffer = 0;
pthread_mutex_t mutex;

void *producer(void *arg)
{
    pthread_mutex_lock(&mutex);

    buffer++;
    printf("Producer produced item = %d\n", buffer);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *consumer(void *arg)
{
    pthread_mutex_lock(&mutex);

    printf("Consumer consumed item = %d\n", buffer);
    buffer--;

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    pthread_t p, c;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}
