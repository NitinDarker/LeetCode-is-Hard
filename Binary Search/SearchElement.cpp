class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int i = (start + end) / 2;
            if (target == nums[i]) {
                return i;
            } else if (target < nums[i]) {
                end = i - 1;
            } else {
                start = i + 1;
            }
        }
        return -1;
    }
};
