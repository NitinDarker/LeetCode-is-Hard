/// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int maxLength = 0;
        int i = 0, j = 0;
        while (j < n) {
            freq[nums[j]]++;
            while (freq[nums[j]] > k) {
                freq[nums[i]]--;
                i++;
            }
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        return maxLength;
    }
};
