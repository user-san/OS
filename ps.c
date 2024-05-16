#include <stdio.h>
#include <stdbool.h>


struct Process {
    int process_id;
    int priority;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    bool completed;
};


int findHighestPriority(struct Process processes[], int n, int current_time) {
    int highest_priority = 9999; 
    int process_index = -1;

    for (int i = 0; i < n; i++) {
        if (!processes[i].completed && processes[i].arrival_time <= current_time && processes[i].priority < highest_priority) {
            highest_priority = processes[i].priority;
            process_index = i;
        }
    }

    return process_index;
}


void preemptive_priority(struct Process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        int highest_priority_index = findHighestPriority(processes, n, current_time);

        if (highest_priority_index == -1) {
            current_time++; 
            continue;
        }

        processes[highest_priority_index].remaining_time--;
        current_time++;

        for (int i = 0; i < n; i++) {
            if (i != highest_priority_index && !processes[i].completed && processes[i].arrival_time <= current_time) {
                processes[i].waiting_time++;
            }
        }

        if (processes[highest_priority_index].remaining_time == 0) {
            processes[highest_priority_index].turnaround_time = current_time - processes[highest_priority_index].arrival_time;
            processes[highest_priority_index].waiting_time = processes[highest_priority_index].turnaround_time - processes[highest_priority_index].burst_time; // Update waiting time
            processes[highest_priority_index].completed = true;
            completed_processes++;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        int process_id = i + 1;
        printf("Enter priority for process %d: ", process_id);
        scanf("%d", &processes[i].priority);
        printf("Enter arrival time for process %d: ", process_id);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", process_id);
        scanf("%d", &processes[i].burst_time);
        processes[i].process_id = process_id;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].completed = false;
    }

    preemptive_priority(processes, n);

    printf("// Order of process Execution is\n");
    printf("Process Id\tPriority\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].priority, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    int total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
    }
    float avg_waiting_time = (float)total_waiting_time / n;

    int total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += processes[i].turnaround_time;
    }
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("The average waiting Time: %.2f\n", avg_waiting_time);
    printf("The average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}

