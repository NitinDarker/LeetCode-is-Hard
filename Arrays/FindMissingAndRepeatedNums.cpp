// https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<int> ans;
        set<int> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mpp.find(grid[i][j]) != mpp.end()) {
                    ans.push_back(grid[i][j]);
                }
                mpp.insert(grid[i][j]);
            }
        }
        int num = 1;
        for (auto &i : mpp) {
            if (i != num) {
                ans.push_back(num);
                break;
            }
            num++;
        }
        if (ans.size() < 2) {
            ans.push_back(n*n);
        }
        return ans;
    }
};
