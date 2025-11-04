// https://www.geeksforgeeks.org/problems/geek-jump/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution1 {
    int f(int ind, vector<int> &height, vector<int> &dp) {
        if (dp[ind] != -1) {
            return dp[ind];
        }
        if (ind == 0 || ind == 1) {
            return dp[ind] = abs(height[ind] - height[0]);
        }
        return dp[ind] = min(abs(height[ind] - height[ind - 1]) + f(ind - 1, height, dp),
                             abs(height[ind] - height[ind - 2]) + f(ind - 2, height, dp));
    }

  public:
    int minCost(vector<int> &height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return f(n - 1, height, dp);
    }
};

// Tabulation
class Solution {
  public:
    int minCost(vector<int> &height) {
        int n = height.size();
        vector<int> dp(n, 0);
        dp[1] = abs(height[1] - height[0]);
        for (int ind = 2; ind < n; ind++) {
            dp[ind] = min(abs(height[ind] - height[ind - 1]) + dp[ind - 1],
                          abs(height[ind] - height[ind - 2]) + dp[ind - 2]);
        }
        return dp[n - 1];
    }
};
