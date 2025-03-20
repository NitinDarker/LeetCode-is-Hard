// https://leetcode.com/problems/single-number/submissions/1580666098/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int sum = 0;
        for (int ele : nums) {
            sum ^= ele;
        }
        return sum;
    }
};
