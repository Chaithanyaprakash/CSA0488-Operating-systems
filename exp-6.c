#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int burst_time;
    int priority;
    int remaining_time;
} Process;

int findHighestPriorityProcess(Process processes[], int n) {
    int highest_priority = -1;
    int highest_priority_index = -1;
    for (int i = 0; i < n; i++) {
        if (processes[i].remaining_time > 0 && (highest_priority == -1 || processes[i].priority < highest_priority)) {
            highest_priority = processes[i].priority;
            highest_priority_index = i;
        }
    }
    return highest_priority_index;
}

void priorityScheduling(Process processes[], int n) {
    int remaining_processes = n;
    int current_time = 0;
    
    while (remaining_processes > 0) {
        int index = findHighestPriorityProcess(processes, n);
        if (index == -1)
            break;
        
        printf("Executing process %d for 1 unit\n", processes[index].pid);
        processes[index].remaining_time--;
        current_time++;
        
        if (processes[index].remaining_time == 0) {
            printf("Process %d completed at time %d\n", processes[index].pid, current_time);
            remaining_processes--;
        }
    }
}

int main() {
    int n;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times and priorities for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Process %d - Priority: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
    }

    priorityScheduling(processes, n);

    return 0;
}
