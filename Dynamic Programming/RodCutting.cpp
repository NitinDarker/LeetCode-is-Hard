// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int i, int len, vector<vector<int>> &dp, vector<int> &price) {
        if (dp[i][len] != -1) return dp[i][len];
        if (i == 0) {
            return len * price[i];
        }
        int notTake = f(i-1, len, dp, price);
        int take = 0;
        if (i+1 <= len) take = price[i] + f(i, len-i-1, dp, price);
        return dp[i][len] = max(take, notTake);
    }

  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(n-1, n, dp, price);
    }
};


// Tabulation
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        for (int i = 0; i <= n; i++) dp[0][i] = n * price[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                int notTake = dp[i-1][j];
                int take = 0;
                if (i + 1 <= j) take = price[i] + dp[i][j-i-1];
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n-1][n];
    }
};
