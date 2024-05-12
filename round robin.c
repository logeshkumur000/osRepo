#include <stdio.h>

#define MAX_PROCESS 10

// Structure to represent a process
struct Process {
    int pid;        // Process ID
    int burst;      // Burst time
    int remaining;  // Remaining burst time
};

// Function to perform Round Robin scheduling
void roundRobin(struct Process processes[], int n, int quantum) {
    int remaining[MAX_PROCESS]; // Array to store remaining burst time for each process
    int currentTime = 0; // Current time

    // Initialize remaining burst time for each process
    for (int i = 0; i < n; i++) {
        remaining[i] = processes[i].burst;
    }

    printf("Execution Sequence:\n");
    while (1) {
        int done = 1; // Flag to check if all processes are completed

        // Traverse each process and execute it for a time quantum
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0; // There are pending processes
                if (remaining[i] > quantum) {
                    printf("Process %d runs for time quantum %d\n", processes[i].pid, quantum);
                    remaining[i] -= quantum;
                    currentTime += quantum;
                } else {
                    printf("Process %d runs for remaining time %d\n", processes[i].pid, remaining[i]);
                    currentTime += remaining[i];
                    remaining[i] = 0; // Process completed
                }
            }
        }

        if (done) // All processes completed
            break;
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Input burst time for each process
    struct Process processes[MAX_PROCESS];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst);
        processes[i].pid = i + 1; // Assign process IDs sequentially
    }

    // Perform Round Robin scheduling
    roundRobin(processes, n, quantum);

    return 0;
}
