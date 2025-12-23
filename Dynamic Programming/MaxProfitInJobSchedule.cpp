// https://leetcode.com/problems/maximum-profit-in-job-scheduling/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findNextIdx(int cur, vector<vector<int>> &events) {
        int l = cur + 1, r = events.size() - 1;
        int val = events[cur][1];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] >= val) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    int f(int ind, vector<vector<int>> &events, vector<int> &dp) {
        if (ind >= events.size()) return 0;
        if (dp[ind] != -1) return dp[ind];
        int take = events[ind][2] + f(findNextIdx(ind, events), events, dp);
        int notTake = f(ind+1, events, dp);
        return dp[ind] = max(take, notTake);
    }

  public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        int n = startTime.size();
        vector<vector<int>> events;
        for (int i = 0; i < n; i++) {
            events.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(events.begin(), events.end());
        vector<int> dp(n, -1);
        return f(0, events, dp);
    }
};
