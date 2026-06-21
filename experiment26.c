#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char data[100];

    /* Create and Write */
    fp = fopen("sample.txt", "w");

    if(fp == NULL)
    {
        printf("File cannot be created\n");
        return 1;
    }

    printf("Enter text to write into file: ");
    fgets(data, sizeof(data), stdin);

    fprintf(fp, "%s", data);
    fclose(fp);

    printf("\nData written successfully.\n");

    /* Read */
    fp = fopen("sample.txt", "r");

    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    printf("\nContents of File:\n");

    while(fgets(data, sizeof(data), fp))
    {
        printf("%s", data);
    }

    fclose(fp);

    return 0;
}
