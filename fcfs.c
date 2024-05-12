#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
};

// Function to calculate waiting time for each process
void calculateWaitingTime(struct Process processes[], int n, int waitingTimes[]) {
    int currentTime = 0; // Current time
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrival)
            currentTime = processes[i].arrival;
        waitingTimes[i] = currentTime - processes[i].arrival; // Waiting time = current time - arrival time
        currentTime += processes[i].burst; // Update current time
    }
}

// Function to calculate average waiting time
float calculateAverageWaitingTime(int waitingTimes[], int n) {
    float totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTimes[i];
    }
    return totalWaitingTime / n;
}

// Function to display the waiting time for each process
void displayWaitingTime(struct Process processes[], int waitingTimes[], int n) {
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival, processes[i].burst, waitingTimes[i]);
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
    }

    // Calculate waiting time for each process
    int waitingTimes[n];
    calculateWaitingTime(processes, n, waitingTimes);

    // Display waiting time for each process
    displayWaitingTime(processes, waitingTimes, n);

    // Calculate and display average waiting time
    float avgWaitingTime = calculateAverageWaitingTime(waitingTimes, n);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);

    return 0;
}
