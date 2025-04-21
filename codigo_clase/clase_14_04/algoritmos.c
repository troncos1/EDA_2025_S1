//><

#include <stdio.h>

// Function to implement bubble sort
void bubbleSort(int array[], int size) {
    // Loop to access each array element
    for (int step = 0; step < size - 1; step++) {
        // Flag to optimize if no swapping occurs in a pass
        int swapped = 0;
        
        // Loop to compare array elements
        for (int i = 0; i < size - step - 1; i++) {
            // Compare two adjacent elements
            if (array[i] > array[i + 1]) {
                // Swap if elements are in wrong order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                
                // Set flag to true if swap happens
                swapped = 1;
            }
        }
        
        // If no swapping occurred in this pass, array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function to test the bubble sort
int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Unsorted Array: \n");
    printArray(data, size);
    
    // Call the bubbleSort function
    bubbleSort(data, size);
    
    printf("Sorted Array in Ascending Order: \n");
    printArray(data, size);
    
    return 0;
}