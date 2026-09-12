#include <stdio.h>
#include <string.h>

// Structure to store customer details
typedef struct {
    char name[50];
    int category;      // 1 = Differently abled, 2 = Senior citizen, 3 = Defence personnel, 4 = Ordinary
    int arrival_order; // Tracks original position for FCFS tie-breaking
} Customer;

// Function to get category name for printing
const char* get_category_name(int cat) {
    switch(cat) {
        case 1: return "Differently Abled";
        case 2: return "Senior Citizen";
        case 3: return "Defence Personnel";
        case 4: return "Ordinary / Normal";
        default: return "Unknown";
    }
}

// Function to sort customers based on priority, then arrival order
void process_priority_queue(Customer arr[], int n) {
    Customer temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            // Condition 1: Higher priority comes first (Lower category number = Higher priority)
            if (arr[j].category > arr[j + 1].category) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            // Condition 2: If priority is the same, use FCFS (Arrival Order)
            else if (arr[j].category == arr[j + 1].category) {
                if (arr[j].arrival_order > arr[j + 1].arrival_order) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }

        }
    }
}

int main() {
    // Sample input queue as they arrive at the post office
    Customer queue[] = {
        {"Alice", 4, 1},  // Ordinary
        {"Bob", 2, 2},    // Senior citizen
        {"Charlie", 1, 3},// Differently abled
        {"David", 3, 4},  // Defence personnel
        {"Emma", 2, 5},    // Senior citizen (arrived after Bob)
        {"Frank", 1, 6}   // Differently abled (arrived after Charlie)
    };

    int n = sizeof(queue) / sizeof(queue[0]);

    printf("--- Original Arrival Queue ---\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %s (%s)\n", i+1, queue[i].name, get_category_name(queue[i].category));
    }

    // Process the queue based on priorities
    process_priority_queue(queue, n);

    printf("\n--- Final Completion Sequence ---\n");
    for (int i = 0; i < n; i++) {
        printf("Served %d: %s [%s]\n", i + 1, queue[i].name, get_category_name(queue[i].category));
    }

    return 0;
}
