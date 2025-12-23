// https://leetcode.com/problems/maximum-earnings-from-taxi/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int findNextIdx(int cur, vector<vector<int>> &rides) {
        int l = cur + 1, r = rides.size() - 1;
        int val = rides[cur][1];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (rides[mid][0] >= val) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    long long f(int ind, vector<vector<int>> &rides, vector<long long> &dp) {
        if (ind >= rides.size()) return 0;
        if (dp[ind] != -1) return dp[ind];
        long long take = (rides[ind][1]-rides[ind][0]+rides[ind][2]) + f(findNextIdx(ind, rides), rides, dp);
        long long notTake = f(ind+1, rides, dp);
        return dp[ind] = max(take, notTake);
    }

  public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
        sort(rides.begin(), rides.end());
        vector<long long> dp(rides.size(), -1);
        return f(0, rides, dp);
    }
};
