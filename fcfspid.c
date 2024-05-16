#include <stdio.h>

struct prodet {
    int pid;
    int start;
    int end;
    int tat;
    int wt;
};

int main() {
    int n, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n];
    struct prodet pro[n];
    printf("Enter the process id for %d processes: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }
    int bust[n], arr[n];
    for (i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", pid[i]);
        scanf("%d", &bust[i]);
        arr[i] = i;
    }
    int ord[n];
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (bust[i] > bust[j]) {
                int t = bust[i];
                bust[i] = bust[j];
                bust[j] = t;
                t = pid[i];
                pid[i] = pid[j];
                pid[j] = t;
            }
        }
    }
    int fin = 0;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            pro[i].pid = pid[i];
            pro[i].start = arr[i];
            pro[i].end = bust[i];
            fin = pro[i].end;
        } else {
            pro[i].pid = pid[i];
            pro[i].start = fin;
            pro[i].end = pro[i].start + bust[i];
            fin = pro[i].end;
        }
    }
    for (i = 0; i < n; i++) {
        pro[i].tat = pro[i].end - arr[i];
        pro[i].wt = pro[i].tat - bust[i];
        if (pro[i].wt < 0) {
            pro[i].wt = 0;
        }
    }
    printf("The order of processes under execution is:\n");
    printf("PID\tStart\tEnd\tTAT\tWait\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", pro[i].pid, pro[i].start, pro[i].end, pro[i].tat, pro[i].wt);
    }

    float avgwt = 0, avgtat = 0;
    for (i = 0; i < n; i++) {
        avgwt += pro[i].wt;
        avgtat += pro[i].tat;
    }
    avgwt = avgwt / n;
    avgtat = avgtat / n;
    printf("%.2f is the average waiting time\n%.2f is the average turnaround time\n", avgwt, avgtat);

    return 0;
}

