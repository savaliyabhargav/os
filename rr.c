#include <stdio.h>

int main() {
    int n, i, time = 0, remain, flag = 0, ts;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n]; // Arrival, Burst, Remaining time
    remain = n;
    
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // copy burst time to remaining time
    }

    printf("Enter Time Slice: ");
    scanf("%d", &ts);

    int wt = 0, tat = 0; // waiting and turnaround times

    printf("\nProcess\tBurst\tTurnaround\tWaiting\n");

    for (time = 0, i = 0; remain != 0; ) {
        if (rt[i] <= ts && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= ts;
            time += ts;
        }

        if (rt[i] == 0 && flag == 1) {
            remain--;
            printf("P[%d]\t%d\t%d\t\t%d\n", i + 1, bt[i], time - at[i], time - at[i] - bt[i]);
            wt += time - at[i] - bt[i];
            tat += time - at[i];
            flag = 0;
        }

        // next process logic
        if (i == n - 1)
            i = 0;
        else if (at[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\nAverage Waiting Time = %.2f", (float)wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)tat / n);
    return 0;
}
