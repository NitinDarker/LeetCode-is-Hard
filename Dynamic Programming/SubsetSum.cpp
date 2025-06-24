// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
#include <bits/stdc++.h>
using namespace std;

// Memoization
bool f(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {
    if (dp[i][target] != -1) return dp[i][target];
    if (target == 0) return dp[i][target] = 1;
    if (i == 0) return dp[i][target] = (nums[0] == target);

    bool notTake = f(i-1, target, nums, dp);
    bool take = false;
    if (nums[i] <= target) take = f(i-1, target-nums[i], nums, dp);
    return dp[i][target] = (take || notTake);
}

bool isSubsetSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return f(n-1, target, nums, dp);
}


// Tabulation
bool subsetSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    for (int i = 0; i < n; i++) dp[i][0] = 1;
    if (nums[0] <= target) dp[0][nums[0]] = 1; 

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool notTake = dp[i-1][j];
            bool take = false;
            if (nums[i] <= j) take = dp[i-1][j-nums[i]];
            dp[i][j] = (take || notTake);
        }
    }
    return dp[n-1][target];
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    if (subsetSum(arr, k)) cout << "Subset with the given target found";
    else cout << "Subset with the given target not found";
    return 0;
}
