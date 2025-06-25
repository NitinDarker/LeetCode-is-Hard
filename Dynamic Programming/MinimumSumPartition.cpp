// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<bool>> fillSubsetSum(int target, vector<int> &nums) {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notTake = dp[i-1][j];
                bool take = false;
                if (nums[i] <= j) take = dp[i-1][j-nums[i]];
                dp[i][j] = (take | notTake);
            }
        }
        return dp;
    }

  public:
    int minimumDifference(vector<int> &nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int ele : nums) totalSum += ele;
        vector<vector<bool>> dp = fillSubsetSum(totalSum, nums);

        int mini = INT_MAX;
        for (int j = 0; j <= totalSum/2; j++) {
            if (dp[n-1][j]) {
                int s1 = j, s2 = totalSum - j;
                mini = min(mini, abs(s1-s2));
            }
        }
        return mini;
    }
};
