// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/?envType=daily-question&envId=2025-06-12
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = 0;
        int i = 0, j = 1;
        do {
            maxDiff = max(maxDiff, abs(nums[i]-nums[j]));
            i++;
            j = (j + 1) % n;
        } while (j != 1);
        return maxDiff;
    }
};
