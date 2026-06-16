#include <stdio.h>
#include <pthread.h>

void *thread1_func(void *arg)
{
    printf("Hello from Thread 1\n");
    return NULL;
}

void *thread2_func(void *arg)
{
    printf("Hello from Thread 2\n");
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1_func, NULL);
    pthread_create(&t2, NULL, thread2_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Threads executed successfully\n");

    return 0;
}
