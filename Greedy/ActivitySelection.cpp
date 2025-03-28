// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int, int>> interval;
        int n = start.size();
        for (int i = 0; i < n; i++) {
            interval.push_back({finish[i], start[i]});
        }
        sort(interval.begin(), interval.end());
        int lastFinish = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (interval[i].second > lastFinish) {
                count++;
                lastFinish = interval[i].first;
            }
        }
        return count;
    }
};
