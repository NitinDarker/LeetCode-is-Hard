/// // https://leetcode.com/problems/longest-increasing-subsequence/description/
// 300. Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int ind, int prev, const vector<int> &nums, vector<vector<int>> &dp) {
        if (ind == nums.size())
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];
        int notTake = f(ind + 1, prev, nums, dp);
        int take = 0;
        if (prev == -1 || nums[prev] < nums[ind])
            take = 1 + f(ind + 1, ind, nums, dp);
        return dp[ind][prev + 1] = max(take, notTake);
    }

  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }
};

// Tabulation
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int notTake = dp[i + 1][j + 1];
                int take = 0;
                if (j == -1 || nums[j] < nums[i])
                    take = 1 + dp[i + 1][i + 1];
                dp[i][j + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};

// Space-Optimization
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> ahead(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr(n + 1, 0);
            for (int j = i - 1; j >= -1; j--) {
                int notTake = ahead[j + 1];
                int take = 0;
                if (j == -1 || nums[j] < nums[i])
                    take = 1 + ahead[i + 1];
                curr[j + 1] = max(take, notTake);
            }
            ahead = curr;
        }
        return ahead[0];
    }
};

//--- Method-2 --- (Still O(n^2))
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<long long> dp(n, 1);
        long long maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

//--- Method-3 --- (Binary Search O(n*logn))
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                continue;
            }
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
        // temp array DOES NOT contain LIS
        return temp.size();
    }
};
