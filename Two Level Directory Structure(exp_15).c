#include <stdio.h>
#include <string.h>

struct Directory
{
    char dirname[50];
    char filename[20][50];
    int filecount;
};

int main()
{
    struct Directory dir[10];
    int dcount = 0;
    int choice;
    char dname[50], fname[50];

    do
    {
        printf("\n----- Two Level Directory -----\n");
        printf("1. Create Directory\n");
        printf("2. Create File\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Directory Name: ");
                scanf("%s", dir[dcount].dirname);
                dir[dcount].filecount = 0;
                dcount++;
                printf("Directory Created Successfully\n");
                break;

            case 2:
            {
                int found = 0;

                printf("Enter Directory Name: ");
                scanf("%s", dname);

                for(int i = 0; i < dcount; i++)
                {
                    if(strcmp(dir[i].dirname, dname) == 0)
                    {
                        printf("Enter File Name: ");
                        scanf("%s", fname);

                        strcpy(dir[i].filename[dir[i].filecount], fname);
                        dir[i].filecount++;

                        printf("File Created Successfully\n");
                        found = 1;
                        break;
                    }
                }

                if(!found)
                    printf("Directory Not Found\n");

                break;
            }

            case 3:
                printf("\nDirectory Structure:\n");

                for(int i = 0; i < dcount; i++)
                {
                    printf("\n%s\n", dir[i].dirname);

                    for(int j = 0; j < dir[i].filecount; j++)
                    {
                        printf("   %s\n", dir[i].filename[j]);
                    }
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 4);

    return 0;
}
