#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    dir = opendir(".");

    if(dir == NULL)
    {
        printf("Unable to open directory\n");
        return 1;
    }

    printf("Files in Current Directory:\n\n");

    while((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
        count++;
    }

    printf("\nTotal Files/Directories = %d\n", count);

    closedir(dir);

    return 0;
}
