// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int mod = 1e9 + 7;
    vector<string> states = {
        "010", "012",
        "020", "021",
        "101", "102",
        "120", "121",
        "201", "202",
        "210", "212"};

  public:
    int solve(int n, int idx, vector<vector<int>> &dp) {
        if (n == 0) return 1;
        if (dp[n][idx] != -1) return dp[n][idx];
        int res = 0;
        string last = states[idx];
        for (int i = 0; i < 12; i++) {
            if (i == idx) continue;
            string curr = states[i];
            bool conflict = false;
            for (int k = 0; k < 3; k++) {
                if (last[k] == curr[k]) {
                    conflict = true;
                    break;
                }
            }
            if (!conflict) {
                res = (res + solve(n-1, i, dp)) % mod;
            }
        }
        return dp[n][idx] = res;
    }

    int numOfWays(int n) {
        int res = 0;
        vector<vector<int>> dp(n, vector<int> (12, -1));
        for (int i = 0; i < 12; i++) {
            res = (res + solve(n-1, i, dp)) % mod;
        }
        return res;
    }
};
