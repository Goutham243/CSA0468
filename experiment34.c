#include <stdio.h>

int main()
{
    int start, length, i;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter length of file: ");
    scanf("%d", &length);

    printf("\nAllocated Blocks:\n");

    for(i = 0; i < length; i++)
    {
        printf("%d ", start + i);
    }

    return 0;
}
