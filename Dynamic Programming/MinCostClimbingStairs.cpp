/// https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=problem-list-v2&envId=dynamic-programming
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int ind, const vector<int> &cost, vector<int> &dp) {
        if (ind <= 1) return 0;
        if (dp[ind] != -1) return dp[ind];
        return min(f(ind-1, cost, dp) + cost[ind-1], f(ind-2, cost, dp) + cost[ind-2]);
    }

  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return f(n, cost, dp);
    }
};

// Tabulation
class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};
