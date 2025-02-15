// https://leetcode.com/problems/plus-one/description/?envType=problem-list-v2&envId=math
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        int carry = 1;
        for (int i = n-1; i >= 0; i--) {
            if (carry == 0) break;
            if (digits[i] == 9) {
                carry = 1;
                digits[i] = 0;
                continue;
            }
            digits[i] += carry;
            carry = 0;
        }
        if (carry == 1) {
            digits.push_back(1);
            swap(digits[0], digits[n]);
        }
        return digits;
    }
};
