/// https://leetcode.com/problems/largest-divisible-subset/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n, 0);
        int maxLen = 1, ind = 0;
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]) {
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
        while (hash[ind] != ind) {
            ind = hash[ind];
            res.push_back(nums[ind]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
