/* 1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int more = target - nums[i];
            if (mpp.find(more) != mpp.end()) {
                ans.push_back(i);
                ans.push_back(mpp[more]);
                break;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};
