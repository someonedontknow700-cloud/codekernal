#include <stdio.h>

void fcfs(int p[], int n, int at[], int bt[])
{
    int wt[n], tat[n], ct[n];

    int total_wt = 0;
    int total_tat = 0;

    // Completion Time
    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++)
    {
        if (ct[i - 1] < at[i])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    // Turnaround Time and Waiting Time
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];

        wt[i] = tat[i] - bt[i];

        total_wt += wt[i];

        total_tat += tat[i];
    }

    // Print Table
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i],
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);
    }

    // Average
    printf("\nAverage Waiting Time = %.2f",
           (float)total_wt / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           (float)total_tat / n);
}

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int arrival_time[n];
    int burst_time[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &burst_time[i]);

        processes[i] = i + 1;
    }

    fcfs(processes, n, arrival_time, burst_time);

    return 0;
}