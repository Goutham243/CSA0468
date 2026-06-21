#include <stdio.h>
#include <pthread.h>

void *thread1(void *arg)
{
    printf("Thread 1 Executing\n");
    pthread_exit(NULL);
}

void *thread2(void *arg)
{
    printf("Thread 2 Executing\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    if(pthread_equal(t1, t2))
        printf("Threads are Equal\n");
    else
        printf("Threads are Not Equal\n");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Threads Joined Successfully\n");

    return 0;
}
