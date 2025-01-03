class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long prefixSum = 0;
        for (int i: nums) {
            prefixSum += i;
        }
        long long leftSum = 0, rightSum = prefixSum;
        int count = 0;
        for (int i = 0; i < n-1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            if (leftSum >= rightSum) count++;
        }
        return count;
    }
};
