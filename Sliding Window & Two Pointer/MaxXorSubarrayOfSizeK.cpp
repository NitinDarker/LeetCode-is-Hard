// https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarrayXOR(vector<int> &arr, int k) {
        int n = arr.size();
        int l = 0, r = 0;
        int maxSum = 0;
        while (r < k) { 
            maxSum ^= arr[r];
            r++;
        }
        int curSum = maxSum;
        while (r < n) {
            curSum ^= arr[l];
            curSum ^= arr[r];
            maxSum = max(maxSum, curSum);
            l++;
            r++;
        }
        return maxSum;
    }
};
