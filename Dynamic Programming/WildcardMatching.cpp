/// https://leetcode.com/problems/wildcard-matching/description/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    bool f(int i, int j, const string &pattern, const string &str, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        if (j < 0 && i >= 0) {
            for (int k = 0; k <= i; k++) {
                if (pattern[k] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (pattern[i] == str[j] || pattern[i] == '?') return dp[i][j] =  f(i-1, j-1, pattern, str, dp);
        if (pattern[i] == '*') return dp[i][j] = f(i-1, j, pattern, str, dp) || f(i, j-1, pattern, str, dp);
        return false;
    }

  public:
    bool isMatch(string str, string pattern) {
        int n = str.length(), m = pattern.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, pattern, str, dp);
    }
};


// Tabulation
class Solution {
  public:
    bool isMatch(string str, string pattern) {
        int n = pattern.length(), m = str.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;
        for (int j = 1; j <= m; j++) dp[0][j] = false;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int k = 0; k < i; k++) {
                if (pattern[k] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pattern[i-1] == str[j-1] || pattern[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                if (pattern[i-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};
