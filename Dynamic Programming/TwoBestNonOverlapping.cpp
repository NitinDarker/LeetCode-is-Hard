// https://leetcode.com/problems/two-best-non-overlapping-events/

// Memoization
class Solution {
    int findNextIdx(int cur, vector<vector<int>> &events) {
        int l = cur+1, r = events.size()-1;
        int val = events[cur][1] + 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (events[mid][0] >= val) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;   
    }

    int f(int ind, int count, vector<vector<int>> &events, vector<vector<int>> &dp) {
        if (ind >= events.size() || count >= 2) return 0;
        if (dp[ind][count] != -1) return dp[ind][count];
        int take = events[ind][2] + f(findNextIdx(ind, events), count+1, events, dp);
        int notTake = f(ind+1, count, events, dp);
        return dp[ind][count] = max(take, notTake);
    }

  public:
    int maxTwoEvents(vector<vector<int>> &events) {
        vector<vector<int>> dp(events.size() ,vector<int> (2, -1));
        sort(events.begin(), events.end());
        return f(0, 0, events, dp);
    }
};


// Tabulation
class Solution {
    int findNextIdx(int cur, vector<vector<int>> &events) {
        int l = cur+1, r = events.size()-1;
        int val = events[cur][1] + 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (events[mid][0] >= val) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;   
    }

  public:
    int maxTwoEvents(vector<vector<int>> &events) {
        int n = events.size();
        vector<vector<int>> dp(n+1 ,vector<int> (3, 0));
        sort(events.begin(), events.end());
        for (int ind = n-1; ind >= 0; ind--) {
            for (int count = 1; count >= 0; count--) {
                int take = events[ind][2] + dp[findNextIdx(ind, events)][count+1];
                int notTake = dp[ind+1][count];
                dp[ind][count] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};
