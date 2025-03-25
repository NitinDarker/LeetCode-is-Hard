// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/?envType=daily-question&envId=2025-03-25
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return (a[0] < b[0]);
    }

    bool countNonOverlapping(vector<vector<int>> &intervals) {
        int n = intervals.size();

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        int j = 0; // Pointer to Result vector

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < res[j][1]) {
                res[j][1] = max(res[j][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                j++;
            }
        }
        return (res.size() > 3);
    }

  public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
        vector<vector<int>> x, y;
        for (vector<int> &coor : rectangles) {
            x.push_back({coor[0], coor[2]});
            y.push_back({coor[1], coor[3]});
        }

        sort(x.begin(), x.end(), comp);
        sort(y.begin(), y.end(), comp);

        return (countNonOverlapping(x) || countNonOverlapping(y));
    }
};
