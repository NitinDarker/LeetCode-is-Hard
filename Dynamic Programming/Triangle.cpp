// https://leetcode.com/problems/triangle/description/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
    int dpHelper(int i, int j, vector<vector<int>> &dp, const vector<vector<int>> tri) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == tri.size() - 1) {
            return tri[i][j];
        }
        return dp[i][j] = tri[i][j] + min(dpHelper(i+1, j, dp, tri), dpHelper(i+1, j+1, dp, tri));
    }

  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return dpHelper(0, 0, dp, triangle);
    }
};


// Tabulation
class Solution2 {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        for (int i = m-1; i >= 0; i--) {
            for (int j = triangle[i].size() - 1; j >= 0; j--) {
                if (i == m-1) {
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

// Space Optmization
class Solution3 {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        for (int i = m-2; i >= 0; i--) {
            for (int j = triangle[i].size()-1; j >= 0; j--) {    
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
