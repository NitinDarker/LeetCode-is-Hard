/// https://leetcode.com/problems/longest-string-chain/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(string &s1, string &s2) {
        if (s1.length() != s2.length() + 1) return false;
        int l = 0;
        int r = 0;
        while (l != s1.length()) {
            if (r < s2.length() && s1[l] == s2[r]) {
                l++;
                r++;
            } else {
                l++;
            }
        }
        if (l == s1.size() && r == s2.size()) return true;
        return false;
    }

  public:
    int longestStrChain(vector<string> &nums) {
        sort(nums.begin(), nums.end(), [](string &s1, string &s2) { return s1.size() < s2.size(); });
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (isPossible(nums[i], nums[prev]) && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
            }
        }
        return maxLen;
    }
};
