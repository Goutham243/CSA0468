#include <stdio.h>
#include <string.h>

int main()
{
    char text[10][100];
    char word[50];
    int n, i, found = 0;

    printf("Enter number of lines: ");
    scanf("%d", &n);
    getchar();

    printf("Enter text:\n");

    for(i = 0; i < n; i++)
    {
        fgets(text[i], sizeof(text[i]), stdin);
    }

    printf("Enter word to search: ");
    scanf("%s", word);

    printf("\nMatching Lines:\n");

    for(i = 0; i < n; i++)
    {
        if(strstr(text[i], word))
        {
            printf("%s", text[i]);
            found = 1;
        }
    }

    if(!found)
        printf("Word not found\n");

    return 0;
}
