/// https://leetcode.com/problems/count-sorted-vowel-strings/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int len, int i, vector<vector<int>> &dp) {
        if (len == 0) return 1;
        if (i == 5 && len != 0) return 0;
        if (dp[i][len] != -1) return dp[i][len];
        return dp[i][len] = f(len-1, i, dp) + f(len, i+1, dp);
    }

  public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5, vector<int>(n+1, -1));
        return f(n, 0, dp);
    }
};

// Tabulation
class Solution {
  public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(6, vector<int>(n+1, 0)); 
        for (int i = 0; i < 5; i++) dp[i][0] = 1;
        for (int i = 4; i >= 0; i--) {
            for (int len = 1; len <= n; len++) {
                dp[i][len] = dp[i][len - 1] + dp[i + 1][len];
            }
        }
        return dp[0][n];
    }
};
