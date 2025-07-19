/// leetcode.com/problems/partition-array-for-maximum-sum/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
  public:
    int f(int i, int n, vector<int> &arr, int k, vector<int> &dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int sum = 0;
        int maxi = arr[i];
        for (int m = 0; m < k; m++) {
            if (i + m < n) {
                maxi = max(maxi, arr[i + m]);
                sum = max(sum, maxi * (m + 1) + f(m + 1 + i, n, arr, k, dp));
            }
        }
        dp[i] = sum;
        return sum;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, n, arr, k, dp);
    }
};

// Tabulation
class Solution {
  public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;
            int maxi = arr[i];
            for (int m = 0; m < k; m++) {
                if (i + m < n) {
                    maxi = max(maxi, arr[i + m]);
                    sum = max(sum, maxi * (m + 1) + dp[m + 1 + i]);
                }
            }
            dp[i] = sum;
        }
        return dp[0];
    }
};
