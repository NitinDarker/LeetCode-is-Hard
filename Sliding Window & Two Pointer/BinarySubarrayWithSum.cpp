// https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Subarrays with sum <= goal
    int f(vector<int> &nums, int goal) {
        if (goal < 0) return 0;
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, cnt = 0;
        while (r < n) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            cnt += (r-l);
            r++;
        }
        return cnt;
    }

  public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        return f(nums, goal) - f(nums, goal-1);
    }
};
