#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int at[n];
    int bt[n];
    int wt[n];
    int tat[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &bt[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int k = at[i];
        int k_t = bt[i];
        int j = i - 1;
        while (j >= 0 && at[j] > k)
        {
            at[j + 1] = at[j];
            bt[j + 1] = bt[j];
            j--;
        }
        at[j + 1] = k;
        bt[j + 1] = k_t;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d", at[i], bt[i]);
        printf("\n");
    }

    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct + bt[i] - at[i];
        ct = ct + bt[i];
    }

    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d", at[i], bt[i]);
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d  %d", at[i], bt[i], tat[i], wt[i]);
        printf("\n");
    }

    int t_wt = 0;
    for (int i = 0; i < n; i++)
    {
        t_wt += wt[i];
    }

    printf("Average wait time: %d", (t_wt / n));
}