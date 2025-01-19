// Q1. Sum of Variable Length Subarrays -> LeetCode Contest (Easy)
// You are given an integer array nums of size n. For each index i where 0 <= i < n, define a subarray
// nums[start ... i] where start = max(0, i - nums[i]).
// Return the total sum of all elements from the subarray defined for each index in the array.

class Solution {
  public:
    int subarraySum(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefixArray(n);
        prefixArray[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixArray[i] = prefixArray[i - 1] + nums[i];
        }
        long long ansSum = 0;
        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]); 
            if (start == 0) {
                ansSum += prefixArray[i];
            } else {
                ansSum += prefixArray[i] - prefixArray[start - 1];
            }
        }
        return ansSum;
    }
};
