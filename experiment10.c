#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    struct message msg;

    key_t key = 1234;

    int msgid = msgget(key, 0666 | IPC_CREAT);

    if(msgid == -1)
    {
        printf("Message Queue Creation Failed\n");
        return 1;
    }

    msg.msg_type = 1;

    printf("Enter message: ");
    fgets(msg.msg_text, sizeof(msg.msg_text), stdin);

    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);

    printf("Message Sent: %s", msg.msg_text);

    msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);

    printf("Message Received: %s", msg.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
