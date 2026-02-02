// https://leetcode.com/problems/maximum-sum-circular-subarray/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int kadane(vector<int> &arr) {
        int n = arr.size();
        int maxSum = INT_MIN, curSum = 0;
        for (int i = 0; i < n; i++) {
            curSum += arr[i];
            maxSum = max(maxSum, curSum);
            if (curSum < 0) curSum = 0;
        }
        return maxSum;
    }

    int wrapSum(vector<int> &arr) {
        int n = arr.size();
        int minSum = INT_MAX, curSum = 0, arrSum = 0;
        
        // Min Kadane
        for (int i = 0; i < n; i++) {
            arrSum += arr[i];
            curSum += arr[i];
            if (curSum > 0) curSum = 0;
            minSum = min(minSum, curSum);
        }

        return arrSum - minSum;
    }

  public:
    int maxSubarraySumCircular(vector<int> &arr) {
        int maxKadane = kadane(arr);
        int wrap = wrapSum(arr);
        if (maxKadane < 0) return maxKadane;
        return max(maxKadane, wrap);
    }
};
