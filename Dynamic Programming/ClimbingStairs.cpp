#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dpClimb(int n, vector<int> &dp) {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = dpClimb(n - 1, dp) + dpClimb(n - 2, dp);
        return dp[n];
    }

  public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return dpClimb(n, dp);
    }
};