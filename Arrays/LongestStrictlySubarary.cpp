// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2025-02-03

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int Bigmaxi = 0;
        for (int i = 0; i < n; i++) {
            int currNum = 1;
            int lastCell = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > lastCell) {
                    lastCell = nums[j];
                    currNum++;
                } else {
                    break;
                }
            }
            Bigmaxi = max(Bigmaxi, currNum);
        }
        int smallMaxi = 0;
        for (int i = 0; i < n; i++) {
            int currNum = 1;
            int lastCell = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < lastCell) {
                    lastCell = nums[j];
                    currNum++;
                } else {
                    break;
                }
            }
            smallMaxi = max(smallMaxi, currNum);
        }
        return max(Bigmaxi, smallMaxi);
    }
};
