// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumDifference(vector<int> &nums, int k) {
        int n = nums.size();
        if (k == 1) return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = k;
        int diff = nums[r-1] - nums[l];
        while (r < n) {
            l++;
            r++;
            diff = min(diff, nums[r-1] - nums[l]);
        }
        return diff;
    }
};
