/// https://leetcode.com/problems/burst-balloons/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int maxi = INT_MIN;
                for (int ind = i; ind <= j; ind++) {
                    int cost = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind - 1] + dp[ind + 1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};
