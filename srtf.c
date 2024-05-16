#include <stdio.h>

struct Process {
    int process_id;
    int burst_time;
    int remaining_time; 
    int arrival_time;   
    int waiting_time;   
    int turnaround_time; 
};


void srtf(struct Process processes[], int n) {
    int completed_processes = 0;
    int current_time = 0;
    int shortest_index;

    while (completed_processes < n) {
        shortest_index = -1;
        int shortest_time = __INT_MAX__;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_time) {
                shortest_index = i;
                shortest_time = processes[i].remaining_time;
            }
        }

        if (shortest_index == -1) {
            current_time++;
            continue;
        }

        processes[shortest_index].remaining_time--;
        current_time++;

        for (int j = 0; j < n; j++) {
            if (j != shortest_index && processes[j].remaining_time > 0 && processes[j].arrival_time <= current_time) {
                processes[j].waiting_time++;
            }
        }

        if (processes[shortest_index].remaining_time <= 0) {
            completed_processes++;
            processes[shortest_index].turnaround_time = current_time - processes[shortest_index].arrival_time;
            processes[shortest_index].waiting_time = processes[shortest_index].turnaround_time - processes[shortest_index].burst_time;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

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

    srtf(processes, n);

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
