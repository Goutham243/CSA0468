#include <stdio.h>

int main()
{
    int pages[50], frame[10], time[10];
    int n, f, i, j, faults = 0, cnt = 0;
    int found, least, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                cnt++;
                time[j] = cnt;
                found = 1;
            }
        }

        if(!found)
        {
            least = time[0];
            pos = 0;

            for(j = 1; j < f; j++)
            {
                if(time[j] < least)
                {
                    least = time[j];
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            cnt++;
            time[pos] = cnt;
            faults++;
        }
    }

    printf("Total Page Faults = %d\n", faults);

    return 0;
}
