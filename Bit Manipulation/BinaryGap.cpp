// https://leetcode.com/problems/binary-gap/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int binaryGap(int n) {
        int pos = 0;
        int lastOne = -1;
        int maxGap = 0;
        while (n > 0) {
            int digit = (n & 1);
            if (digit == 1) {
                if (lastOne != -1)  {
                    maxGap = max(maxGap, pos-lastOne);
                }
                lastOne = pos;
            }
            n = (n >> 1);
            pos++;
        }
        return maxGap;
    }
};
