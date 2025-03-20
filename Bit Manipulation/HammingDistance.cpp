// https://leetcode.com/problems/hamming-distance/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n-1);
            count++;
        }
        return count;
    }

  public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        return countSetBits(diff);
    }
};
