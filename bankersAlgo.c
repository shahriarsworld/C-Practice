#include <stdio.h>

#define MAX_PROCESS 10
#define MAX_RESOURCE 10

void calculateNeedMatrix(int need[MAX_PROCESS][MAX_RESOURCE],
                         int maxAllocation[MAX_PROCESS][MAX_RESOURCE],
                         int allocation[MAX_PROCESS][MAX_RESOURCE],
                         int nProcess, int nResource)
{
    for (int i = 0; i < nProcess; i++)
    {
        for (int j = 0; j < nResource; j++)
        {
            need[i][j] = maxAllocation[i][j] - allocation[i][j];
        }
    }o
}

int isSafeState(int available[MAX_RESOURCE], int maxAllocation[MAX_PROCESS][MAX_RESOURCE],
                int allocation[MAX_PROCESS][MAX_RESOURCE], int need[MAX_PROCESS][MAX_RESOURCE],
                int nProcess, int nResource, int safeSequence[MAX_PROCESS])
{
    int work[MAX_RESOURCE];
    int finish[MAX_PROCESS] = { 0 };

    for (int i = 0; i < nResource; i++)
    {
        work[i] = available[i];
    }

    int completed = 0;
    while (completed < nProcess)
    {
        int safe = 0;
        for (int i = 0; i < nProcess; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < nResource; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }
                if (j == nResource)
                {
                    for (int k = 0; k < nResource; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    safeSequence[completed] = i; // Record the safe sequence
                    safe = 1;
                    completed++;
                }
            }
        }
        if (!safe)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int nProcess, nResource;
    int maxAllocation[MAX_PROCESS][MAX_RESOURCE];
    int allocation[MAX_PROCESS][MAX_RESOURCE];
    int available[MAX_RESOURCE];
    int safeSequence[MAX_PROCESS];

    printf("Enter the number of processes: ");
    scanf("%d", &nProcess);

    printf("Enter the number of resources: ");
    scanf("%d", &nResource);

    printf("Enter the maximum allocation matrix:\n");
    for (int i = 0; i < nProcess; i++)
    {
        for (int j = 0; j < nResource; j++)
        {
            scanf("%d", &maxAllocation[i][j]);
        }
    }

    printf("Enter the current allocation matrix:\n");
    for (int i = 0; i < nProcess; i++)
    {
        for (int j = 0; j < nResource; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (int i = 0; i < nResource; i++)
    {
        scanf("%d", &available[i]);
    }

    int need[MAX_PROCESS][MAX_RESOURCE];
    calculateNeedMatrix(need, maxAllocation, allocation, nProcess, nResource);

    if (isSafeState(available, maxAllocation, allocation, need, nProcess, nResource, safeSequence))
    {
        printf("\n");

        printf("Need Matrix:\n");
        for (int i = 0; i < nProcess; i++)
        {
            for (int j = 0; j < nResource; j++)
            {
                printf("%d ", need[i][j]);
            }
            printf("\n");
        }

        printf("Safe Sequence: ");
        for (int i = 0; i < nProcess; i++)
        {
            printf("%d ", safeSequence[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Unsafe state\n");
    }

    return 0;
}
