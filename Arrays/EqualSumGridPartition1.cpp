// https://leetcode.com/problems/equal-sum-grid-partition-i/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPartitionGrid(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        long long totalSum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }

        // Horizontal Cut
        long long prefixSum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefixSum += grid[i][j];
            }
            if (prefixSum == totalSum - prefixSum)
                return true;
        }

        // Vertical Cut
        prefixSum = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                prefixSum += grid[i][j];
            }
            if (prefixSum == totalSum - prefixSum)
                return true;
        }
        return false;
    }
};
