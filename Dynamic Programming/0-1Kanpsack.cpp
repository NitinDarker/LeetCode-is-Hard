// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
#include <bits/stdc++.h>
using namespace std;

// Recursion -> Top-Down Approach
int maxProfitRec(int i, int w, const vector<int> &profit, const vector<int> &weight) {
    if (i == 0) {
        int take = INT_MIN;
        if (weight[0] <= w) take = profit[0]; 
        int notTake = 0;
        return max(take, notTake);
    }
    int take = INT_MIN;
    if (weight[i] <= w) take = profit[i] + maxProfitRec(i-1, w-weight[i], profit, weight);
    int notTake = 0 + maxProfitRec(i-1, w, profit, weight);
    return max(take, notTake);
}

// Memoization -> Recursion + DP (for overlapping sub-problems)
int maxProfitDP(int i, int w, vector<vector<int>> &dp, vector<int> &profit, vector<int> &weight) {
    if (i == 0) {
        int take = INT_MIN;
        if (weight[0] <= w) take = profit[0];
        int notTake = 0;
        dp[0][w] = max(take, notTake);
        return dp[0][w];
    }
    if (dp[i][w] != -1) return dp[i][w];
    int take = INT_MIN;
    if (weight[i] <= w) take = profit[i] + maxProfitDP(i - 1, w - weight[i], dp, profit, weight);
    int notTake = 0 + maxProfitDP(i - 1, w, dp, profit, weight);
    dp[i][w] = max(take, notTake);
    return dp[i][w];
}

// Tabulation -> Bottom-Up Approach
int maxProfitTab(vector<int> &profit, vector<int> &weight, int maxWeight) {
    int n = profit.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    for (int i = weight[0]; i <= maxWeight; i++) {
        dp[0][i] = profit[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            int take = INT_MIN;
            if (weight[i] <= w) take = profit[i] + dp[i - 1][w - weight[i]];
            int notTake = 0 + dp[i - 1][w];
            dp[i][w] = max(take, notTake);
        }
    }
    cout << "DP Table: " << endl;
    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return dp[n-1][maxWeight];

}

int main() {
    int n = 4; // Number of objects
    int maxWeight = 10;
    vector<int> weight = {1, 4, 9, 7}; 
    vector<int> profit = {6, 2, 8, 7};

    cout << maxProfitTab(profit, weight, maxWeight);
    return 0;
}
