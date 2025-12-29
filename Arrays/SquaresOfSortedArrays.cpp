// https://leetcode.com/problems/squares-of-a-sorted-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        int pivot = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int l = pivot - 1, r = pivot;
        vector<int> res;
        while (l >= 0 && r < n) {
            if (nums[l]*nums[l] <= nums[r]*nums[r]) res.push_back(nums[l]*nums[l--]);
            else res.push_back(nums[r]*nums[r++]);
        }
        while (l >= 0) res.push_back(nums[l]*nums[l--]);
        while (r < n) res.push_back(nums[r]*nums[r++]);
        return res;
    }
};
