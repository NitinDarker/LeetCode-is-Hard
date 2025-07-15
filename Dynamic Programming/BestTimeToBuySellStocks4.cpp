// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int f(int ind, int tran, vector<vector<int>> &dp, const vector<int> &prices, int k) {
        if (ind == prices.size() || tran == 2*k) return 0;
        if (dp[ind][tran] != -1) return dp[ind][tran];

        int profit = 0;
        if (tran % 2 == 0) { // Buy
            int take = -prices[ind] + f(ind + 1, tran + 1, dp, prices, k);
            int notTake = f(ind + 1, tran, dp, prices, k);
            profit = max(take, notTake);
        } else { // Sell
            int sell = prices[ind] + f(ind + 1, tran + 1, dp, prices, k);
            int notSell = f(ind + 1, tran, dp, prices, k);
            profit = max(sell, notSell);
        }

        return dp[ind][tran] = profit;
    }

  public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return f(0, 0, dp, prices, k);
    }
};


// Tabulation ->
class Solution {
  public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(k*2+1, 0));
        for (int day = n-1; day >= 0; day--) {
            for (int tran = 1; tran <= 2*k; tran++) {
                int profit = 0;
                if (tran % 2 == 0) { // Buy
                    int buy = -prices[day] + dp[day+1][tran-1];
                    int notBuy = dp[day+1][tran];
                    profit = max(buy, notBuy);
                } else { // Sell
                    int sell = prices[day] + dp[day+1][tran-1];
                    int notSell = dp[day+1][tran];
                    profit = max(sell, notSell);
                }
                dp[day][tran] = profit;
            }
        }
        return dp[0][2*k];
    }
};

// Space Optimization
class Solution {
  public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector<int> after(k*2 + 1, 0);
        for (int day = n-1; day >= 0; day--) {
            vector<int> curr(k*2 + 1, 0);
            for (int tran = 1; tran <= 2*k; tran++) {
                int profit = 0;
                if (tran % 2 == 0) { // Buy
                    int buy = -prices[day] + after[tran-1];
                    int notBuy = after[tran];
                    profit = max(buy, notBuy);
                } else { // Sell
                    int sell = prices[day] + after[tran-1];
                    int notSell = after[tran];
                    profit = max(sell, notSell);
                }
               curr[tran] = profit;
            }
            after = curr;
        }
        return after[2*k];
    }
};
