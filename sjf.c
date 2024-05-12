#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int completion; // Completion time
    int turnaround; // Turnaround time
    int waiting;    // Waiting time
    int executed;   // Flag to mark if process has been executed
};

// Function to swap two processes
void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform sorting based on burst time (SJF)
void sortByBurst(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst > processes[j + 1].burst) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

// Function to calculate turnaround time, waiting time, and completion time for each process
void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        processes[i].completion = currentTime + processes[i].burst;
        processes[i].turnaround = processes[i].completion - processes[i].arrival;
        processes[i].waiting = processes[i].turnaround - processes[i].burst;
        currentTime = processes[i].completion;
    }
}

// Function to display process details
void displayProcessDetails(struct Process processes[], int n) {
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival, processes[i].burst, 
            processes[i].completion, processes[i].turnaround, processes[i].waiting);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst);
        processes[i].pid = i + 1; // Assign process IDs sequentially
        processes[i].executed = 0; // Initialize executed flag to 0
    }

    // Sort processes based on burst time (SJF)
    sortByBurst(processes, n);

    // Calculate completion time, turnaround time, and waiting time for each process
    calculateTimes(processes, n);

    // Display process details
    displayProcessDetails(processes, n);

    return 0;
}
