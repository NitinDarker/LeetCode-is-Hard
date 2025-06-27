// https://leetcode.com/problems/target-sum/description/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int i, int target, vector<vector<int>> &dp, vector<int> &nums) {
        if (dp[i][target] != -1) return dp[i][target];
        if (i == 0) {
            if (target == 0 && nums[0] == 0) return 2; // pick + notPick
            else if (target == 0) return 1; // notPick
            else if (target == nums[0]) return 1; // pick
            return 0;
        }
        int notPick = f(i-1, target, dp, nums);
        int pick = 0;
        if (nums[i] <= target) pick = f(i-1, target-nums[i], dp, nums);
        return dp[i][target] = pick + notPick;
    }

  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (int ele : nums) totalSum += ele;

        if ((totalSum < target) || ((totalSum-target) & 1) == 1) return 0;

        int reqSum = (totalSum-target)/2;
        vector<vector<int>> dp(n, vector<int>(reqSum+1, -1));
        return f(n-1, reqSum, dp, nums);
    }
};
