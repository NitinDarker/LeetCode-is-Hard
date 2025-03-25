// https://leetcode.com/problems/merge-intervals/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Comparator to sort intervals based on start time
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }

  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        int j = 0; // Pointer to Result vector

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= res[j][1]) {
                res[j][1] = max(res[j][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                j++;
            }
        }
        return res;
    }
};