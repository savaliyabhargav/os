#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], ct[n], tat[n], wt[n];
    int i, j, temp;
    float avg_tat = 0, avg_wt = 0;

    // Input burst and arrival times
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    // --- Sort by Arrival Time (simple bubble sort) ---
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arrival[i] > arrival[j]) {
                // swap arrival
                temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;
                // swap burst
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
            }
        }
    }

    // --- Calculate Completion Time (CT), Turnaround (TAT), Waiting (WT) ---
    ct[0] = arrival[0] + burst[0];  // first process finishes after its burst
    for (i = 1; i < n; i++) {
        if (arrival[i] > ct[i - 1])
            ct[i] = arrival[i] + burst[i];  // CPU idle until process arrives
        else
            ct[i] = ct[i - 1] + burst[i];   // process starts right after previous
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - arrival[i];
        wt[i] = tat[i] - burst[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    // --- Print Output ---
    printf("\nPNo\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, arrival[i], burst[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turn Around Time: %.2f", avg_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);

    return 0;
}
