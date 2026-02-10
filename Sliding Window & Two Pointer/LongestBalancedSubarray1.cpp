// https://leetcode.com/problems/longest-balanced-subarray-i/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestBalanced(vector<int> &nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> even, odd;
            for (int j = i; j < n; j++) {
                if ((nums[j] & 1) == 1 && odd.count(nums[j]) == 0) odd.insert(nums[j]);
                else if ((nums[j] & 1) == 0 && even.count(nums[j]) == 0) even.insert(nums[j]);  
                if (even.size() == odd.size()) res = max(res, j-i+1);
            }
        }
        return res;
    }
};
