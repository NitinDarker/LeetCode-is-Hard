/// https://leetcode.com/problems/palindrome-partitioning-ii/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
  public:
    bool palindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else return false;
        }
        return true;
    }

    int f(int i, string &s, vector<int> &dp) {
        if (i >= s.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = 1e7;
        for (int k = i; k < s.size(); k++) {
            if (palindrome(i, k, s)) {
                int cost = 1 + f(k + 1, s, dp);
                ans = min(ans, cost);
            }
        }
        dp[i] = ans;
        return ans;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp) - 1;
    }
};

// Tabulation
class Solution {
  public:
    bool palindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else  return false;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int ans = 1e9;
            for (int j = i; j < n; j++) {
                if (palindrome(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    ans = min(ans, cost);
                }
            }
            dp[i] = ans;
        }
        return dp[0] - 1;
    }
};
