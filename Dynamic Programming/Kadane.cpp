// https://leetcode.com/problems/maximum-subarray/
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int currSum = 0, maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            currSum += arr[i];
            maxSum = max(maxSum, currSum);
            if (currSum < 0) currSum = 0;
        }
        return maxSum;
    }
};
