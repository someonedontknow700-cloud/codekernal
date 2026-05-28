#include <stdio.h>

int main() {
    int n, tq;

    int at[10], bt[10], rt[10];
    int wt[10], tat[10];

    int time = 0, done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Arrival time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    while (done < n) {

        int executed = 0;

        for (int i = 0; i < n; i++) {

            if (rt[i] > 0 && at[i] <= time) {

                executed = 1;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                }
                else {
                    time += rt[i];

                    tat[i] = time - at[i];
                    wt[i] = tat[i] - bt[i];

                    rt[i] = 0;
                    done++;
                }
            }
        }

        // If no process executed, move time forward
        if (!executed) {
            time++;
        }
    }

    float avgWT = 0, avgTAT = 0;

    printf("\nProcess\tAT\tBT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], tat[i], wt[i]);

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", avgWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT / n);

    return 0;
}