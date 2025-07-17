/// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 1; i--) {
            for (int j = i+1; j < n; j++) {
                int mini = 1e9;
                for (int k = i; k < j; k++) {
                    mini = min(mini, dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
};
