#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int subarrayXor(vector<int> &arr) {
        int n = arr.size();
        int xorSum = 0;
        for (int i = 0; i < n; i++) {
            int cnt = (i+1) * (n-i);
            if (cnt % 2 != 0) {
                xorSum ^= arr[i];
            }
        }
        return xorSum;
    }
};
