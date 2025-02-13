// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/?envType=daily-question&envId=2025-02-13
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Heap {
  public:
    vector<long> arr;
    int size;

    Heap() {
        size = 0;
    }

    // To insert a key in heap Array -> Min Heap
    void insertKey(long key) {
        arr.push_back(key);
        size++;
        int n = size - 1;              // Index for the key
        int parentIndex = (n - 1) / 2; // Index for the parent
        while (parentIndex >= 0 && n > 0) {
            if (arr[parentIndex] <= key) {
                break;
            }
            swap(arr[parentIndex], arr[n]);
            n = parentIndex;
            parentIndex = (n - 1) / 2;
        }
    }

    // To delete root in heap Array -> Min Heap
    void deleteRoot() {
        if (size == 0) {
            return;
        }
        swap(arr[0], arr[size - 1]);
        arr.pop_back();
        size--;

        int currInd = 0;

        while (true) {
            int leftChild = 2 * currInd + 1;
            int rightChild = 2 * currInd + 2;
            int smallest = currInd;

            if (leftChild < size && arr[leftChild] < arr[smallest])
                smallest = leftChild;
            if (rightChild < size && arr[rightChild] < arr[smallest])
                smallest = rightChild;

            if (smallest == currInd)
                break; // Already in correct position

            swap(arr[currInd], arr[smallest]);
            currInd = smallest;
        }
    }

    void printHeap() {
        for (long val : arr) {
            cout << val << " ";
        }
        cout << endl;
    }
};

class Solution {
  public:
    int minOperations(vector<int> &nums, int k) {
        int count = 0;
        Heap minHeap;
        int n = nums.size();
        for (int ele : nums) {
            minHeap.insertKey(ele);
        }
        while (true) {
            long x = minHeap.arr[0];
            if (x >= k) {
                break;
            }
            minHeap.deleteRoot();
            long y = minHeap.arr[0];
            minHeap.deleteRoot();
            long newKey = (long) min(x, y) * 2 + (long) max(x, y);
            minHeap.insertKey(newKey);
            count++;
        }
        return count;
    }
};
