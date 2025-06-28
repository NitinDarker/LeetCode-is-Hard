// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int i, int w, vector<vector<int>> &dp, vector<int> &val, vector<int> &wt) {
        if (dp[i][w] != -1) return dp[i][w];
        if (i == 0) {
            return dp[i][w] = (w/wt[i])*val[i];
        } 
        int notTake = f(i-1, w, dp, val, wt);
        int take = 0;
        if (wt[i] <= w) take = val[i] + f(i, w-wt[i], dp, val, wt);
        return dp[i][w] = max(take, notTake);
    }

  public:
  int knapSack(vector<int> &val, vector<int> &wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        return f(n-1, capacity, dp, val, wt);
    }
};

// Tabulation
class Solution {
  public:
  int knapSack(vector<int> &val, vector<int> &wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
        
        for (int j = 0; j <= capacity; j++) dp[0][j] = (j/wt[0])*val[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= capacity; j++) {
                int notTake = dp[i-1][j];
                int take = 0;
                if (wt[i] <= j) take = val[i] + dp[i][j-wt[i]];
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n-1][capacity];
    }
};
