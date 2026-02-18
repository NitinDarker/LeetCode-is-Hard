// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int merge(int low, int mid, int high, vector<int> &arr) {
        vector<int> merged;
        int inv = 0;
        int p = low, q = mid+1;
        while (p <= mid && q <= high) {
            if (arr[p] <= arr[q]) merged.push_back(arr[p++]);
            else merged.push_back(arr[q++]), inv += (mid-p+1);
        }
        while (p <= mid) merged.push_back(arr[p++]);
        while (q <= high) merged.push_back(arr[q++]);
        for (int i = 0, j = low; i < merged.size(); i++, j++) arr[j] = merged[i];
        return inv;
    }

  public:
    int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;
        int mid = low + (high-low)/2;
        int inv = 0;
        inv += mergeSort(arr, low, mid);
        inv += mergeSort(arr, mid+1, high);
        inv += merge(low, mid, high, arr);
        return inv;
    }

    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size()-1);
    }
};
