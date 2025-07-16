// Printing The Longest Increasing Subsequence
/// https://leetcode.com/problems/longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void printLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n,0);
        for (int i = 0; i < n; i++) hash[i] = i;
        int maxLen = 1, ind = 0;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                ind = i;
            }
        }
        vector<int> res;
        res.push_back(nums[ind]);
        cout << "Longest Increasing Subsequence (Reversed): ";
        while (hash[ind] != ind) {
            ind = hash[ind];
            cout << nums[ind] << " ";
            res.push_back(nums[ind]);
        }
        cout << endl;
        reverse(res.begin(), res.end());
        // return res;
    }
};
