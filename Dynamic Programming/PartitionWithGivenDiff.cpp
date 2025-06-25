// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> subsetSum(vector<int> nums, int target) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        if (nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if (nums[0] != 0 && nums[0] <= target) dp[0][nums[0]] = 1;


        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                int notTake = dp[i-1][j];
                int take = 0;
                if (nums[i] <= j) take = dp[i-1][j-nums[i]];
                dp[i][j] = (take + notTake) % mod;
            }
        }
        return dp;
    }

  public:
    int countPartitions(vector<int> &arr, int d) {
        int n = arr.size();
        int totalSum = 0;
        for (int ele : arr) totalSum += ele;

        if (totalSum - d < 0) return 0;
        if (((totalSum - d) & 1) == 1) return 0;

        int target = (totalSum - d) / 2;
        vector<vector<int>> dp = subsetSum(arr, target);
        return dp[n-1][target];
    }
};
