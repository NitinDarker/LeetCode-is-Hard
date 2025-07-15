// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int ind, bool buy, int cap, vector<vector<vector<int>>> &dp, const vector<int> &prices) {
        if (ind == prices.size() || cap == 0) return 0;
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int profit = 0;
        if (buy) {
            int take = -prices[ind] + f(ind + 1, 0, cap, dp, prices);
            int notTake = f(ind + 1, 1, cap, dp, prices);
            profit = max(take, notTake);
        } else {
            int sell = prices[ind] + f(ind + 1, 1, cap-1, dp, prices);
            int notSell = f(ind + 1, 0, cap, dp, prices);
            profit = max(sell, notSell);
        }
        return dp[ind][buy][cap] = profit;
    }

  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, dp, prices);
    }
};

// Tabulation
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k < 3; k++) {
                    int profit = 0;
                    if (j == 1) {
                        int take = -prices[i] + dp[i + 1][0][k];
                        int notTake = dp[i + 1][1][k];
                        profit = max(take, notTake);
                    } else {
                        int sell = prices[i] + dp[i + 1][1][k-1];
                        int notSell = dp[i + 1][0][k];
                        profit = max(sell, notSell);
                    }
                    dp[i][j][k] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};
