// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    int calculateDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            int unitDigit = num % 10;
            sum += unitDigit;
            num /= 10;
        }
        return sum;
    }

  public:
    int maximumSum(vector<int> &nums) {
        int n = nums.size();
        vector<int> digitSum(n);
        for (int i = 0; i < n; i++) {
            digitSum[i] = calculateDigitSum(nums[i]);
        }
        int maxSum = -1;
        unordered_map <int, int> mpp;
        for (int i = 0; i < n; i++) {
            if (mpp.find(digitSum[i]) != mpp.end()) {
                int valNums = nums[mpp[digitSum[i]]];
                int currSum = nums[i] + valNums;
                maxSum = max(maxSum, currSum);
                if (valNums < nums[i]) {
                    mpp[digitSum[i]] = i;
                }
            } else {
                mpp[digitSum[i]] = i;
            }
        }
        return maxSum;
    }
};
