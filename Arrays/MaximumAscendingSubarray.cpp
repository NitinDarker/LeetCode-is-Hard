// https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int lastCell = nums[i];
            int currSum = nums[i];
            for (int j = i+1; j < n; j++) {
                if (nums[j] > lastCell) {
                    lastCell = nums[j];
                    currSum += lastCell;
                } else {
                    break;
                }
            }
            maxi = max(maxi, currSum);
        }
        return maxi;
    }
};
