// https://leetcode.com/problems/trionic-array-i/?envType=daily-question&envId=2026-02-03
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        while (i < n && nums[i-1] < nums[i]) i++;
        if (i == n || i == 1) return false;
        while (i < n && nums[i-1] > nums[i]) i++;
        if (i == n) return false;
        while (i < n && nums[i-1] < nums[i]) i++;
        if (i == n) return true;
        return false;
    }
};
