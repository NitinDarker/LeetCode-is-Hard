class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long prefix = 0;
        for (int i: nums) {
            prefix += i;
        }
        int mini = INT_MAX;
        int ind = -1;
        long long leftSum = 0, rightSum = prefix;
        for (int i = 0; i < n; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            int leftAvg, rightAvg;
            leftAvg = leftSum/(i+1);
            if (rightSum != 0) rightAvg = rightSum/(n-i-1);
            else rightAvg = 0;
            int avgDiff = abs(leftAvg - rightAvg);
            if (avgDiff < mini) {
                mini = avgDiff;
                ind = i;
            }
        }
        return ind;
    }
};
