// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int minSwaps(vector<int> &nums) {
        // Using Sliding Window
        int n = nums.size();

        // Count total num of 1's
        int countOne = 0;
        for (int ele: nums) {
            if (ele == 1) countOne++;
        }

        int l = 0, r = countOne;
        // Count num of 0's in current sliding window
        int countZero = 0;
        for (int i = l; i < r; i++) {
            if (nums[i] == 0) countZero++;
        }
        // CountZero = num of swaps needed
        int mini = countZero;

        // Edge Case
        if (n == 1) {
            return countZero;
        }

        do {
            if (nums[l] == 0) countZero--;
            if (nums[r] == 0) countZero++;
            l = (l+1) % n;
            r = (r+1) % n;
            mini = min(mini, countZero);
        } while (l != 0);
        return mini;
    }
};
