#include <stdio.h>

#define MAX_BLOCKS 50
#define MAX_PROCESSES 10

// Structure to represent a memory block
typedef struct {
    int starting_address;
    int size;
    int allocated;
} Block;

// Function prototypes
void initialize_memory(Block memory[], int num_blocks);
void display_memory(Block memory[], int num_blocks);
void first_fit(Block memory[], int num_blocks, int process_size);

int main() {
    int num_blocks, num_processes, process_size, i;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &num_blocks);

    Block memory[MAX_BLOCKS];

    initialize_memory(memory, num_blocks);

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("\nEnter the size of process %d: ", i + 1);
        scanf("%d", &process_size);
        first_fit(memory, num_blocks, process_size);
    }

    return 0;
}

// Function to initialize memory blocks
void initialize_memory(Block memory[], int num_blocks) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        printf("Enter the starting address and size of block %d: ", i + 1);
        scanf("%d %d", &memory[i].starting_address, &memory[i].size);
        memory[i].allocated = 0;
    }
}

// Function to display memory
void display_memory(Block memory[], int num_blocks) {
    int i;
    printf("\nMemory Blocks:\n");
    printf("Start\tSize\tAllocated\n");
    for (i = 0; i < num_blocks; i++) {
        printf("%d\t%d\t%s\n", memory[i].starting_address, memory[i].size, memory[i].allocated ? "Yes" : "No");
    }
}

// Function to allocate memory using first fit algorithm
void first_fit(Block memory[], int num_blocks, int process_size) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if (memory[i].allocated == 0 && memory[i].size >= process_size) {
            memory[i].allocated = 1;
            printf("Memory allocated successfully for process of size %d at starting address %d.\n", process_size, memory[i].starting_address);
            display_memory(memory, num_blocks);
            return;
        }
    }
    printf("Memory allocation failed for the process of size %d.\n", process_size);
}
