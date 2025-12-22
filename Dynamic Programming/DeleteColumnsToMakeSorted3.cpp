// https://leetcode.com/problems/delete-columns-to-make-sorted-iii
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size(), cols = strs[0].length();
        vector<int> dp(cols, 1);
        int lis = 1;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < i; j++) {
                bool valid = true;
                for (int row = 0; row < rows; row++) {
                    if (strs[row][j] > strs[row][i]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    dp[i] = max(dp[i], dp[j]+1);
                    lis = max(lis, dp[i]);
                }
            }
        }
        return cols - lis;
    }
};
