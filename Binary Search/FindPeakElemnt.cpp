// https://leetcode.com/problems/find-peak-element/
class Solution {
  public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l <= r) {
            int mid = l + (r-l) / 2;
            int cur = nums[mid];
            if ((mid == 0 || cur >= nums[mid-1]) && (mid == n-1 || cur >= nums[mid+1])) {
                return mid;
            } else if (mid > 0 && cur < nums[mid-1]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
