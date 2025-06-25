// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int i, int target, const vector<int> &arr, vector<vector<int>> &dp) {
        if (dp[i][target] != -1) return dp[i][target];
        if (i == 0) {
            if (target == 0 && arr[0] == 0) return 2;  // two subsets: pick or not pick
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }        
        int notPick = f(i-1, target, arr, dp);
        int pick = 0;
        if (arr[i] <= target) pick = f(i-1, target-arr[i], arr, dp);
        return dp[i][target] = pick + notPick;
    }

  public:
    int perfectSum(vector<int> &arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, arr, dp);
    }
};

// Tabulation
class Solution {
  public:
    int perfectSum(vector<int> &arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));

        dp[0][0] = (arr[0] == 0) ? 2 : 1;
        if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                int notPick = dp[i-1][j];
                int pick = 0;
                if (arr[i] <= j) pick = dp[i-1][j-arr[i]];
                dp[i][j] = pick + notPick;
            }
        }
        return dp[n-1][target];
    }
};
