// https://leetcode.com/problems/first-missing-positive/description/
#include <bits/stdc++.h>
using namespace std;

// Using Extra Space
class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        vector<int> vis(n+1, 0);
        for (int num : nums) {
            if (num > 0 && num <= n) {
                vis[num] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) return i;
        }
        return n+1;
    }
};

// Constant Space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
