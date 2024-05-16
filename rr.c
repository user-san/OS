#include <stdio.h>


struct Process {
    int process_id;
    int burst_time;
    int remaining_time; 
    int arrival_time;  
    int waiting_time;   
    int turnaround_time;
};

void round_robin(struct Process processes[], int n, int time_quantum) {
    int completed_processes = 0;
    int current_time = 0;

    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time <= 0)
                continue;

            for (int j = 0; j < n; j++) {
                if (j != i && processes[j].remaining_time > 0 && processes[j].arrival_time <= current_time && processes[j].waiting_time == 0) {
                    processes[j].waiting_time = current_time - processes[j].arrival_time;
                }
            }

            int execute_time = (processes[i].remaining_time < time_quantum) ? processes[i].remaining_time : time_quantum;
            processes[i].remaining_time -= execute_time;
            current_time += execute_time;

            if (processes[i].remaining_time <= 0 && processes[i].turnaround_time == 0) {
                completed_processes++;
                processes[i].turnaround_time = current_time - processes[i].arrival_time;
                processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
            }
        }
    }
}

int main() {
    int n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter arrival time for process P%d: ", processes[i].process_id);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process P%d: ", processes[i].process_id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    round_robin(processes, n, time_quantum);

    printf("// Order of process Execution is\n");
    printf("Process Id\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;

    printf("The average waiting Time: %.2f\n", avg_waiting_time);
    printf("The average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}
