#include <stdio.h>

void calcAvgTimes(int p[], int n, int bt[], int wt[], int tat[]) {
    float avgWt = 0, avgTat = 0;

    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        avgWt += wt[i];
        avgTat += tat[i];
    }

    avgWt /= n;
    avgTat /= n;

    printf("\nAvg Waiting Time: %.2f", avgWt);
    printf("\nAvg Turnaround Time: %.2f", avgTat);
}

void fcfs(int p[], int n, int bt[]) {
    int wt[n], tat[n];

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
    printf("\nFCFS (First Come First Serve) Scheduling:\n");
    printf("\nFCFS Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("- P%d [%d] -", p[i], wt[i]);
    }
    printf("-\n");

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t0\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    calcAvgTimes(p, n, bt, wt, tat);
}

void sjf(int p[], int n, int bt[]) {
    int wt[n], tat[n];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
    printf("\nSJF (Shortest Job First) Scheduling:\n");
    printf("\nSJF Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("- P%d [%d] -", p[i], wt[i]);
    }
    printf("-\n");

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t0\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    calcAvgTimes(p, n, bt, wt, tat);
}

int main() {
    int n;

    printf("How many processes are added? : ");
    scanf("%d", &n);

    int p[n], bt[n];

    printf("Now enter Burst Time for given %d processes:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        p[i] = i + 1;
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    fcfs(p, n, bt);
    sjf(p, n, bt);

    return 0;
}
