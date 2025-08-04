// https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int kadane(vector<int> arr) {
        int n = arr.size();
        int currSum = 0, maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            currSum += arr[i];
            maxSum = max(maxSum, currSum);
            if (currSum < 0) currSum = 0;
        }
        return maxSum;
    }

  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int row = mat.size(), col = mat[0].size();
        int maxi = INT_MIN;
        for (int i = 0; i < col; i++) {
            vector<int> dp(row, 0);
            for (int j = i; j < col; j++) {
                for (int k = 0; k < row; k++) {
                    dp[k] += mat[k][j];
                }
                maxi = max(maxi, kadane(dp));
            }
        }
        return maxi;
    }
};
