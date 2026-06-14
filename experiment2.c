#include <stdio.h>

int main()
{
    FILE *source, *destination;
    char ch;
    char sourceFile[100], destFile[100];

    printf("Enter source file name: ");
    scanf("%s", sourceFile);

    source = fopen(sourceFile, "r");

    if (source == NULL)
    {
        printf("Source file not found\n");
        return 1;
    }

    printf("Enter destination file name: ");
    scanf("%s", destFile);

    destination = fopen(destFile, "w");

    if (destination == NULL)
    {
        printf("Cannot create destination file\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("Contents copied successfully.\n");

    return 0;
}
