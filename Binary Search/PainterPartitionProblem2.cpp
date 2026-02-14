// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int helper(int cap, vector<int> &arr) {
        int n = arr.size();
        int p = 1, take = 0;
        for (int i = 0; i < n; i++) {
            if (take + arr[i] > cap) {
                p++;
                take = arr[i];
            } else {
                take += arr[i];
            }
        }
        return p;
    }

  public:
    int splitArray(vector<int> &arr, int k) {
        int n = arr.size();
        int maxi = arr[0], sum = 0;
        for (int ele : arr) {
            maxi = max(maxi, ele);
            sum += ele;
        }
        int low = maxi;
        int high = sum;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (helper(mid, arr) > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
