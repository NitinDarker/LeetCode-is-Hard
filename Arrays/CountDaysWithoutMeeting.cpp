// https://leetcode.com/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-03-24
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Comparator function to sort the meetings based on start day
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return (a[0] < b[0]);
    }

  public:
    int countDays(int days, vector<vector<int>> &meetings) {
        int n = meetings.size();

        sort(meetings.begin(), meetings.end(), comp);
        
        int freeDays = 0;

        // Free Days before starting
        if (meetings[0][0] > 1) {
            freeDays += (meetings[0][0] - 1);
        }

        for (int i = 0; i < n-1; i++) {
            // Count the gap between current-end and next-start
            if ((meetings[i][1] + 1) < meetings[i+1][0]) {
                freeDays += (meetings[i+1][0] - meetings[i][1] - 1);
            }
            // In case of overlap
            if (meetings[i][1] > meetings[i+1][1]) {
                swap(meetings[i][1], meetings[i+1][1]);
            }
        }

        // Free Days after ending
        freeDays += (days - meetings[n-1][1]);

        return freeDays;
    }
};
