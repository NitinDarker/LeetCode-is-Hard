// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int lcs(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) {
            int sum = 0;
            while (i >= 0) sum += a[i--];
            while (j >= 0) sum += b[j--];
            return sum;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (a[i] == b[j]) return dp[i][j] = lcs(a, b, i-1, j-1, dp);
        return dp[i][j] = min(a[i]+lcs(a,b,i-1,j,dp), b[j]+lcs(a,b,i,j-1,dp));
    }

  public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return lcs(s1, s2, m-1, n-1, dp);
    }
};

// Tabulation
class Solution2 {
  public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for (int i = 0; i < m; i++) dp[i+1][0] = s1[i]+dp[i][0];
        for (int j = 0; j < n; j++) dp[0][j+1] = s2[j]+dp[0][j];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(s1[i-1]+dp[i-1][j], s2[j-1]+dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
