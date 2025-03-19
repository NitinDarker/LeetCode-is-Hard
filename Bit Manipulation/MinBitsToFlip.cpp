// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
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
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        return countSetBits(diff);
    }
};
