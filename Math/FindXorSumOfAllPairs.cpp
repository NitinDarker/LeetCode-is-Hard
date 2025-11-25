// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2) {
        int xor2sum = 0;
        for (int &ele : arr2) {
            xor2sum ^= ele;
        }
        int xor1sum = 0;
        for (int ele : arr1) {
            xor1sum ^= (ele & xor2sum);
        }
        return xor1sum;
    }
};
