// 560. Subarray Sum Equals K
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int count = 0;
        int sum = 0;
        for (int i: nums) {
            sum += i;
            if (sum == k) count++;
            int rem = sum - k;
            if (mpp.find(rem) != mpp.end()) {
                count += mpp[rem];
            }
            mpp[sum]++;
        }
        return count;
    }
};
