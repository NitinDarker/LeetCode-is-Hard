/// https://leetcode.com/problems/edit-distance/description/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int i, int j, const string &s, const string &t, vector<vector<int>> &dp) {
        if (i < 0) return j+1;
        if (j < 0) return i+1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) return dp[i][j] = f(i-1, j-1, s, t, dp);
        int insrt = 1 + f(i, j-1, s, t, dp);
        int delet = 1 + f(i-1, j, s, t, dp);
        int rplce = 1 + f(i-1, j-1, s, t, dp);
        return dp[i][j] = min(insrt, min(delet, rplce));
    }

  public:
    int minDistance(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, t, dp);
    }
};

// Tabulation
class Solution {
  public:
    int minDistance(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int insrt = dp[i][j-1];
                int delet = dp[i-1][j];
                int rplce = dp[i-1][j-1];
                if (s[i-1] != t[j-1]) dp[i][j] = 1 + min(insrt, min(delet, rplce));
                else dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};
