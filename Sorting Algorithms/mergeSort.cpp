#include <iostream>
using namespace std;

// Selection Sort is NOT stable -> if same element is present then order may not be maintained
// Selection Sort is NOT adaptive -> Doesn't take advantage of already sorted array

void mergeSort(int *arr, int size) {
    // Divide & Merger Algorithm Approach
    int n = size;
    
} // Time Complexity = O(n*log(n))

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

    mergeSort(arr, size);
    display(arr, size);
    return 0;
}