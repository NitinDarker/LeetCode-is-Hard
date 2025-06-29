/// https://leetcode.com/problems/longest-common-subsequence/description/
#include <bits/stdc++.h>
using namespace std;

// Recursion -> Top-Down Approach
class Solution {
    int f(int i, int j, string &text1, string &text2) {
        if (i < 0 || j < 0) return 0;
        if (text1[i] == text2[j]) return 1 + f(i-1, j-1, text1, text2);
        return max(f(i-1, j, text1, text2), f(i, j-1, text1, text2));
    }

  public:
    int longestCommonSubsequence(string text1, string text2) {
        return f(text1.length()-1, text2.length()-1, text1, text2);
    }
};


// Memoization -> Using DP Array
class Solution {
    int f(int i, int j, const string &text1, const string &text2, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (text1[i] == text2[j]) return dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp);
        return dp[i][j] = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));
    }

  public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n-1, m-1, text1, text2, dp);
    }
};


// Tabulation -> Bottom-Up Approach
class Solution {
 public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};


// Space-Optimized Tabulation
class Solution {
 public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<int> prev(m+1, 0);
        for (int i = 1; i <= n; i++) {
            vector<int> curr(m+1, 0);
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};
