#include <iostream>
using namespace std;

void insertionSort(int *arr, int size) {
    int i, j;

    for (i = 1; i < size; i++) { // For the number of passes
        int ele = arr[i];

       for (j = i - 1; j >= 0; j--) { 
            if (ele < arr[j]) {
                arr[j + 1] = arr[j]; // Shifting the elements
                // arr[j] = ele; // Swapping
            } else {
                break;
            }
        }
        arr[j + 1] = ele; // Inserting the element in sorted fashion
    }
} // Time Complexity = O(n^2)
// Time Complexity (if Sorted) = O(n)

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {565, 654, 66, 2, 67, 99, 109, 34, 90, 71, 0, 16, 6};
    int arr2[] = {1, 2, 4, 5, 6, 8, 9};
    int arr3[] = {1, 3, 8, 2};
    int size = sizeof(arr) / sizeof(int);

    insertionSort(arr, size);
    display(arr, size);
    return 0;
}