class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int low = 0, high = 0;
        while (high < n-1) {
            int farthest = 0;
            for (int i = low; i <= high; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            low = high + 1;
            high = farthest;
            jumps++;
        }
        return jumps;
    }
};
