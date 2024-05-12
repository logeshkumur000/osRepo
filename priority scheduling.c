#include <stdio.h>

#define MAX_PROCESS 10

// Structure to represent a process
struct Process {
    int pid;        // Process ID
    int burst;      // Burst time
    int priority;   // Priority
    int executed;   // Flag to mark if process has been executed
};

// Function to perform Priority scheduling
void priorityScheduling(struct Process processes[], int n) {
    int currentTime = 0;
    int minPriority = processes[0].priority;
    int index = 0;
    int completedProcesses = 0;

    printf("Execution Sequence:\n");
    while (completedProcesses < n) {
        minPriority = 9999; // Reset minPriority for each iteration

        // Find the process with the highest priority
        for (int i = 0; i < n; i++) {
            if (processes[i].executed == 0 && processes[i].priority < minPriority) {
                minPriority = processes[i].priority;
                index = i;
            }
        }

        // Execute the process
        printf("Process %d with burst time %d and priority %d is scheduled.\n", 
               processes[index].pid, processes[index].burst, processes[index].priority);
        currentTime += processes[index].burst;
        processes[index].executed = 1;
        completedProcesses++;
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    struct Process processes[MAX_PROCESS];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].pid = i + 1; // Assign process IDs sequentially
        processes[i].executed = 0; // Initialize executed flag to 0
    }

    // Perform Priority scheduling
    priorityScheduling(processes, n);

    return 0;
}
