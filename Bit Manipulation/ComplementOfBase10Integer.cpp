// https://leetcode.com/problems/complement-of-base-10-integer/?envType=daily-question&envId=2026-03-11
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int bitwiseComplement(int n) {
        int temp = n;
        int pos = 0;
        while (temp > 0) {
            temp >>= 1;
            pos++;
        }
        int res = 0;
        for (int i = 0; i < pos; i++) {
            int bit = !((1 << i) & n);
            res = ((bit << i) | res);
        }
        return res;
    }
};
