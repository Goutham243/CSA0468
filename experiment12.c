#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

void* philosopher(void* arg)
{
    int id = *(int*)arg;

    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    printf("Philosopher %d is thinking...\n", id);

    pthread_mutex_lock(&chopsticks[left]);
    pthread_mutex_lock(&chopsticks[right]);

    printf("Philosopher %d is eating...\n", id);

    sleep(1);

    pthread_mutex_unlock(&chopsticks[left]);
    pthread_mutex_unlock(&chopsticks[right]);

    printf("Philosopher %d finished eating.\n", id);

    return NULL;
}

int main()
{
    pthread_t phil[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];

    for(int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    for(int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        ids[i] = i;
        pthread_create(&phil[i], NULL, philosopher, &ids[i]);
    }

    for(int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_join(phil[i], NULL);
    }

    for(int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_mutex_destroy(&chopsticks[i]);
    }

    return 0;
}
