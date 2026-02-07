// https://leetcode.com/problems/rotate-function/
class Solution {
  public:
    int maxRotateFunction(vector<int> &arr) {
        int n = arr.size();
        int prevSum = 0, arrSum = 0;
        for (int i = 0; i < n; i++) arrSum += arr[i], prevSum += i * arr[i];
        int maxSum = prevSum;
        for (int i = 1; i < n; i++) {
            int sum = prevSum + arrSum - (n * arr[n-i]);
            maxSum = max(maxSum, sum);
            prevSum = sum;
        }
        return maxSum;
    }
};
