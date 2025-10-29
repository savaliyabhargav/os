#include <stdio.h>

int main() {
    int A[100][4]; // Columns: [0]=Process ID, [1]=Burst Time, [2]=Waiting Time, [3]=Turnaround Time
    int n, i, j, index, temp, total = 0;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);   // Burst time
        A[i][0] = i + 1;         // Process ID
    }

    // --- Sort by Burst Time (Shortest Job First) ---
    for (i = 0; i < n - 1; i++) {
        index = i;
        for (j = i + 1; j < n; j++) {
            if (A[j][1] < A[index][1])
                index = j;
        }
        // Swap burst time
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;
        // Swap process ID
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }

    // --- Waiting Time Calculation ---
    A[0][2] = 0; // First process waits 0
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++) {
            A[i][2] += A[j][1]; // waiting time = sum of all previous burst times
        }
        total += A[i][2];
    }
    avg_wt = (float) total / n;

    // --- Turnaround Time Calculation ---
    total = 0;
    printf("\nP\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2]; // TAT = BT + WT
        total += A[i][3];
        printf("P%d\t%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2], A[i][3]);
    }
    avg_tat = (float) total / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
