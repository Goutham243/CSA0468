#include <stdio.h>

int main()
{
    int blockSize[20], processSize[20];
    int allocation[20];
    int m,n,i,j,bestIdx;

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
        bestIdx=-1;

        for(j=0;j<m;j++)
        {
            if(blockSize[j]>=processSize[i])
            {
                if(bestIdx==-1 || blockSize[j]<blockSize[bestIdx])
                    bestIdx=j;
            }
        }

        if(bestIdx!=-1)
        {
            allocation[i]=bestIdx;
            blockSize[bestIdx]-=processSize[i];
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
