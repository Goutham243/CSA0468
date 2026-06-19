#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    key_t key = 1234;
    int shmid;
    char *str;

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    if (shmid < 0)
    {
        printf("Shared memory creation failed\n");
        return 1;
    }

    str = (char *)shmat(shmid, NULL, 0);

    printf("Enter message to write into shared memory: ");
    fgets(str, 1024, stdin);

    printf("\nData written in memory: %s", str);

    printf("\nData read from memory: %s", str);

    shmdt(str);

    return 0;
}
