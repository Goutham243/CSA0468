#include <stdio.h>

void bestfit(int mp[], int p[], int m, int n)
{
    int j = 0;

    for(int i = 0; i < n; i++)
    {
        if(mp[i] >= p[j])
        {
            printf("\n%d fits in %d", p[j], mp[i]);
            mp[i] = mp[i] - p[j++];
            i = i - 1;

            if(j == m)
                break;
        }
    }

    for(int i = j; i < m; i++)
    {
        printf("\n%d must wait for its process", p[i]);
    }
}

void sort(int a[], int n)
{
    int i, j, t;

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void rsort(int a[], int n)
{
    int i, j, t;

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] < a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void firstfit(int mp[], int p[], int m, int n)
{
    sort(mp, n);
    sort(p, m);
    bestfit(mp, p, m, n);
}

void worstfit(int mp[], int p[], int m, int n)
{
    rsort(mp, n);
    sort(p, m);
    bestfit(mp, p, m, n);
}

int main()
{
    int m, n, mp[20], p[20], ch;

    printf("Number of memory partitions: ");
    scanf("%d", &n);

    printf("Number of processes: ");
    scanf("%d", &m);

    printf("Enter memory partitions:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &mp[i]);
    }

    printf("Enter process sizes:\n");

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            firstfit(mp, p, m, n);
            break;

        case 2:
            bestfit(mp, p, m, n);
            break;

        case 3:
            worstfit(mp, p, m, n);
            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}
