#include <stdio.h>
void calcAvg(int p[], int n, int bt[], int wt[], int tat[]) {
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

void roundRobin(int p[], int n, int bt[], int quantum) {
    int wt[n], tat[n], rt[n];

    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    int t = 0, flag = 1;
    printf("\n-------Round Robin Scheduling-------");
    printf("\nRound Robin Gantt Chart:\n");
    while (1) {
        flag = 1;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                flag = 0;
                if (rt[i] > quantum) {
                    t += quantum;
                    rt[i] -= quantum;
                    printf("- P%d[%d] -", p[i], t);
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i];
                    rt[i] = 0;
                    printf("- P%d[%d] -", p[i], t);
                }
            }
        }
        if (flag)
            break;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t0\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    calcAvg(p, n, bt, wt, tat);
}

void priority(int p[], int n, int bt[], int pri[]) {
    int wt[n], tat[n], pos, temp;

    for (int i = 0; i < n; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++) {
            if (pri[j] < pri[pos])
                pos = j;
        }

        temp = pri[i];
        pri[i] = pri[pos];
        pri[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
    printf("\n\n-------Priority Scheduling-------");
    printf("\nPriority Scheduling Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("- P%d[%d] -", p[i], tat[i]);
    }
    printf("\n\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t0\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pri[i], wt[i], tat[i]);
    }

    calcAvg(p, n, bt, wt, tat);
}

int main() {
    int n, quantum;

    printf("How many processes are there to be executed? : ");
    scanf("%d", &n);

    int p[n], bt[n], pri[n];

    printf("-------Enter Burst Times, and Priorities based on Process Numbers-------\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        p[i] = i + 1;
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pri[i]);
    }

    printf("Enter the Time Quantum/Time Slicing for Round Robin: ");
    scanf("%d", &quantum);

    roundRobin(p, n, bt, quantum);
    priority(p, n, bt, pri);

    return 0;
}
