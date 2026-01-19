// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> findPrefix(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m, vector<int> (n));
        prefix[0][0] = mat[0][0];
        for (int i = 1; i < m; i++) prefix[i][0] = prefix[i-1][0] + mat[i][0];
        for (int j = 1; j < n; j++) prefix[0][j] = prefix[0][j-1] + mat[0][j];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mat[i][j];
            }
        }
        return prefix;
    }

  public:
    int maxSideLength(vector<vector<int>> &mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix = findPrefix(mat);
        int maxSide = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = maxSide; k < min(m-i,n-j); k++) {
                    int sum = prefix[i+k][j+k];
                    if (i > 0) sum -= prefix[i-1][j+k];
                    if (j > 0) sum -= prefix[i+k][j-1];
                    if (i > 0 && j > 0) sum += prefix[i-1][j-1];
                    if (sum <= threshold) {
                        maxSide = max(maxSide, k+1);
                    }
                }
            }
        }
        return maxSide;
    }
};
