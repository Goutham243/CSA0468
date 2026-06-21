#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, seek = 0;

    printf("Enter Number of Requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter Request Queue:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter Initial Head Position: ");
    scanf("%d",&head);

    printf("\nHead Movement:\n%d", head);

    for(int i=0;i<n;i++)
    {
        seek += abs(head-req[i]);
        head=req[i];

        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d", seek);
    printf("\nAverage Seek Time = %.2f", (float)seek/n);

    return 0;
}
