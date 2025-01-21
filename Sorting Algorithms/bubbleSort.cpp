#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size) {
    while (size > 1) { // Loop for the number of passes
        int i = 0;
        int j = i + 1; // Used two variables for better understanding

        while (j < size) { // Loop for swapping the elements in a single pass
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
            i++;
            j++; // Incrementing the pointers
        }
        size--;
        // Biggest element is at the end of the array
    }
} // Time Complexity = O(n^2)

void adaptiveBubbleSort(int *arr, int size) {
    while (size > 1) { // Loop for the number of passes
        int i = 0;
        int j = i + 1;        // Used two variables for better understanding
        bool isSorted = true; // used a boolean to check if the array is already sorted

        while (j < size) { // Loop for swapping the elements in a single pass
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
                isSorted = false;
            }
            i++;
            j++; // Incrementing the pointers
        }
        if (isSorted) { // Taking advantage of already sorted array
            return;
        }
        size--;
        // Biggest element is at the end of the array
    }
} // Time Complexity (if Sorted) = O(n)

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {565, 654, 66, 2, 67, 99, 109, 34, 90, 71, 0, 16};
    int arr2[] = {1, 2, 4, 5, 6, 8, 9};
    int size = sizeof(arr) / sizeof(int);

    adaptiveBubbleSort(arr, size);
    display(arr, size);
    return 0;
}
