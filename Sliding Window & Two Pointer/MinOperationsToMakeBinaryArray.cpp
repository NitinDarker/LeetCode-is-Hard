// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/?envType=daily-question&envId=2025-03-19
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minOperations(vector<int> &nums) {
        int n = nums.size();
        // Sliding window
        int l = 0, r = 2;
        int count = 0;
        while (r < n) {
            if (nums[l]) {
                l++;
                r++;
            } else {
                for (int i = l; i <= r; i++)
                    nums[i] == 1 ? nums[i] = 0 : nums[i] = 1;
                l++;
                r++;
                count++;
            }
        }
        if (nums[n-1] && nums[n-2]) return count;
        return -1;
    }
};
