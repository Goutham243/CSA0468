#include <stdio.h>

int main()
{
    int blockSize[20], processSize[20];
    int allocation[20];
    int m,n,i,j;

    printf("Enter number of memory blocks: ");
    scanf("%d",&m);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter block sizes:\n");
    for(i=0;i<m;i++)
        scanf("%d",&blockSize[i]);

    printf("Enter process sizes:\n");
    for(i=0;i<n;i++)
        scanf("%d",&processSize[i]);

    for(i=0;i<n;i++)
        allocation[i]=-1;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(blockSize[j]>=processSize[i])
            {
                allocation[i]=j;
                blockSize[j]-=processSize[i];
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t",i+1,processSize[i]);

        if(allocation[i]!=-1)
            printf("%d\n",allocation[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
