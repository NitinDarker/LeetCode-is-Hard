// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<long, long> mpp;
        mpp[0] = 1;
        long xorSum = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            xorSum ^= arr[i];
            long val = xorSum ^ k;
            if (mpp.find(val) != mpp.end()) cnt += mpp[val];
            mpp[xorSum]++;
        }
        return cnt;
    }
};
