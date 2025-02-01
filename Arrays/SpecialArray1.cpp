/* 3151. Special Array I -> LeetCode Daily Problem

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == 0 && nums[i-1] % 2 == 0) {
                return false;
            } else if (nums[i] % 2 != 0 && nums[i-1] % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};
