// leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts) {
        int cost = 0;
        if (startPos[0] < homePos[0]) {
            // Move down
            for (int i = startPos[0]+1; i <= homePos[0]; i++) {
                cost += rowCosts[i];
            }
        } else {
            // Move Up
            for (int i = startPos[0]-1; i >= homePos[0]; i--) {
                cost += rowCosts[i];
            }
        }
        if (startPos[1] < homePos[1]) {
            // Move right
            for (int j = startPos[1]+1; j <= homePos[1]; j++) {
                cost += colCosts[j];
            }
        } else {
            // Move left
            for (int j = startPos[1]-1; j >= homePos[1]; j--) {
                cost += colCosts[j];
            }
        }
        return cost;
    }
};
