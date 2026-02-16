// https://leetcode.com/problems/reverse-bits/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int digit = n & 1;
            n = n >> 1;
            ans = ((ans << 1) | digit);
        }
        return ans;
    }
};
