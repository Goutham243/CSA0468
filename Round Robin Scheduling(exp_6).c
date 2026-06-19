#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int bt[20], rt[20], pr[20];
    int wt[20] = {0}, tat[20] = {0};
    int min_pr, shortest;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        printf("P%d Priority: ", i + 1);
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    while(completed < n)
    {
        min_pr = 9999;
        shortest = -1;

        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0 && pr[i] < min_pr)
            {
                min_pr = pr[i];
                shortest = i;
            }
        }

        if(shortest == -1)
        {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0)
        {
            completed++;

            tat[shortest] = time;
            wt[shortest] = tat[shortest] - bt[shortest];

            avg_wt += wt[shortest];
            avg_tat += tat[shortest];
        }
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, pr[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
