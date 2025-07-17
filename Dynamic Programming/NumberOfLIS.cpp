/// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<long long> dp(n, 1), cnt(n, 1);
        long long maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && dp[i] < 1+dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev]; // inherit
                } else if (nums[prev] < nums[i] && dp[i] == 1+dp[prev]) {
                    cnt[i] += cnt[prev]; // increase
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen) res += cnt[i];
        }
        return res;
    }
};
