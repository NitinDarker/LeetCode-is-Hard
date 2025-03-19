// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n = (n & (n-1));
            count++;
        }
        return count;
    }

  public:
    int minOperations(vector<int> &nums, int k) {
        int xorSum = 0;
        for (int ele: nums) {
            xorSum ^= ele;
        }
        int diff = xorSum ^ k;
        return __builtin_popcount(diff);
    }
};
