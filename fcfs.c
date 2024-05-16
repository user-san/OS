#include <stdio.h>

int main() {
    int numProcesses, i, j;
    float avgWaitingTime, avgTurnaroundTime, totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    int burstTime[numProcesses], waitingTime[numProcesses], turnaroundTime[numProcesses];

    printf("Enter the burst time for each process:\n");
    for(i=0; i<numProcesses; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &burstTime[i]);
    }

    waitingTime[0] = 0;   

    for(i=1; i<numProcesses; i++) {
        waitingTime[i] = 0;
        for(j=0; j<i; j++)
            waitingTime[i] += burstTime[j];
    }

    for(i=0; i<numProcesses; i++)
        turnaroundTime[i] = burstTime[i] + waitingTime[i];

    for(i=0; i<numProcesses; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    avgWaitingTime = totalWaitingTime / numProcesses;
    avgTurnaroundTime = totalTurnaroundTime / numProcesses;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<numProcesses; i++)
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burstTime[i], waitingTime[i], turnaroundTime[i]);

    printf("\nAverage Waiting Time: %0.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %0.2f\n", avgTurnaroundTime);

    return 0;
}
