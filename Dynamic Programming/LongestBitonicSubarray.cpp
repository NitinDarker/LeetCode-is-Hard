/// https://leetcode.com/problems/longest-mountain-in-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int LongestBitonicSubarray(int n, vector<int> &nums) {
        vector<int> leftLIS(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i-1] < nums[i]) {
                leftLIS[i] += leftLIS[i-1];
            }
        }
        vector<int> rightLIS(n, 1);
        for (int i = n-2; i >= 0; i--) {
            if (nums[i+1] < nums[i]) {
                rightLIS[i] += rightLIS[i+1];
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

  public:
    int longestMountain(vector<int> &nums) {
        int n = nums.size();
        return LongestBitonicSubarray(n, nums);
    }
};
