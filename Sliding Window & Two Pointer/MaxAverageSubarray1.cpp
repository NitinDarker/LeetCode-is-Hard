// https://leetcode.com/problems/maximum-average-subarray-i/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double findMaxAverage(vector<int> &arr, int k) {
        int n = arr.size();
        int l = 0, r = 0;
        int curSum = 0;
        while (r - l != k) {
            curSum += arr[r];
            r++;
        }
        int maxSum = curSum;
        while (r < n) {
            curSum += arr[r];
            curSum -= arr[l];
            maxSum = max(maxSum, curSum);
            l++;
            r++;
        }
        return ((double) maxSum / k);
    }
};
