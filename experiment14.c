#include <stdio.h>
#include <string.h>

#define MAX_FILES 20

char files[MAX_FILES][50];
int count = 0;

void createFile()
{
    if(count >= MAX_FILES)
    {
        printf("Directory Full!\n");
        return;
    }

    printf("Enter file name: ");
    scanf("%s", files[count]);

    count++;

    printf("File created successfully.\n");
}

void displayFiles()
{
    if(count == 0)
    {
        printf("Directory is empty.\n");
        return;
    }

    printf("\nFiles in Directory:\n");

    for(int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, files[i]);
    }
}

void deleteFile()
{
    char name[50];
    int found = 0;

    printf("Enter file name to delete: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++)
    {
        if(strcmp(files[i], name) == 0)
        {
            found = 1;

            for(int j = i; j < count - 1; j++)
            {
                strcpy(files[j], files[j + 1]);
            }

            count--;

            printf("File deleted successfully.\n");
            break;
        }
    }

    if(!found)
    {
        printf("File not found.\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Single Level Directory ---\n");
        printf("1. Create File\n");
        printf("2. Display Files\n");
        printf("3. Delete File\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createFile();
                break;

            case 2:
                displayFiles();
                break;

            case 3:
                deleteFile();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
