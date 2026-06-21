#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Block
{
    char data[100];
    struct Block *next;
};

int main()
{
    struct Block *first = NULL, *last = NULL, *temp;
    int choice, blockNo, count = 0;
    char text[100];

    while(1)
    {
        printf("\n1.Write Block\n2.Read Block\n3.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                temp = (struct Block *)malloc(sizeof(struct Block));

                printf("Enter Data: ");
                scanf(" %[^\n]", temp->data);

                temp->next = NULL;

                if(first == NULL)
                {
                    first = last = temp;
                }
                else
                {
                    last->next = temp;
                    last = temp;
                }

                count++;
                break;

            case 2:
                printf("Enter Block Number: ");
                scanf("%d", &blockNo);

                temp = first;

                for(int i = 1; i < blockNo; i++)
                    temp = temp->next;

                printf("Data = %s\n", temp->data);
                break;

            case 3:
                exit(0);
        }
    }
}
