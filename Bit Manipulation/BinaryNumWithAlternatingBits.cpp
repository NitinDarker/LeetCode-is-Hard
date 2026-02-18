// https://leetcode.com/problems/binary-number-with-alternating-bits/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool check = 0;
        if ((n & 1) == 1) check = 1; 
        while (n > 0) {
            int unit = (n & 1);
            if (unit != check) return false;
            check = !check;
            n = (n >> 1);
        }
        return true;
    }
};

// XOR Trick
class Solution2 {
  public:
    bool hasAlternatingBits(int n) {
        long x = (n ^ (n >> 1));
        return (x & (x+1)) == 0;
    }
};
