// https://leetcode.com/problems/minimum-time-to-make-rope-colorful
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int i = 0, j = 1;
        int minCost = 0;
        while (j < n) {
            int windowMax = neededTime[i], totalCost = neededTime[i];
            while (j < n && colors[i] == colors[j]) {
                totalCost += neededTime[j];
                windowMax = max(windowMax, neededTime[j]);
                j++;
            }
            minCost += (totalCost - windowMax);
            i = j;
            j++;
        }
        return minCost;
    }
};
