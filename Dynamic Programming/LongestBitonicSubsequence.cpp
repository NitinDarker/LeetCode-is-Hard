/// https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> leftLIS(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j  = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    leftLIS[i] = max(leftLIS[i], 1 + leftLIS[j]);
                }
            }
        }
        vector<int> rightLIS(n, 1);
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    rightLIS[i] = max(rightLIS[i], 1 + rightLIS[j]);
                }
            }
        }
        vector<int> bitonic(n, 0);
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            bitonic[i] = leftLIS[i] + rightLIS[i] - 1;
            if (leftLIS[i] == 1 || rightLIS[i] == 1) {
                bitonic[i] = 0;
            }
            maxLength = max(maxLength, bitonic[i]);
        }
        return maxLength;
    }
};
