// https://leetcode.com/problems/max-dot-product-of-two-subsequences

#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp) {
        if (i == nums1.size() || j == nums2.size()) return -1e9;
        if (dp[i][j] != -1e9) return dp[i][j];
        int val = nums1[i] * nums2[j];
        return dp[i][j] = max(val,
                              max(val + solve(i + 1, j + 1, nums1, nums2, dp),
                                  max(solve(i + 1, j, nums1, nums2, dp),
                                      solve(i, j + 1, nums1, nums2, dp))));
    }

  public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1e9));
        return solve(0, 0, nums1, nums2, dp);
    }
};
