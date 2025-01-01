class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int sum1 = 0;
        for (char ch: s) {
            if (ch == '1') {
                sum1++;
            }
        }
        int maxSum = 0;
        int sum0 = 0;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == '0') {
                sum0++;
            } else {
                sum1--;
            }
            int subSum = sum0 + sum1;
            maxSum = max(maxSum, subSum);
        }
        return maxSum;
    }
};
