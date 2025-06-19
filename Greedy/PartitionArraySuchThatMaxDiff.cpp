// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/?envType=daily-question&envId=2025-06-19
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int partitionArray(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0;
        while (i < nums.size()) {
            int maxi = nums[i] + k;
            while (i < nums.size() && nums[i] <= maxi) {
                i++;
            }
            count++;
        }
        return count;
    }
};
