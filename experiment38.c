#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, seek = 0;

    printf("Enter Number of Requests: ");
    scanf("%d",&n);

    int req[n];

    printf("Enter Request Queue:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter Head Position: ");
    scanf("%d",&head);

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(req[i]>req[j])
            {
                int t=req[i];
                req[i]=req[j];
                req[j]=t;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        seek += abs(head-req[i]);
        head=req[i];
    }

    printf("Total Seek Time = %d", seek);

    return 0;
}
