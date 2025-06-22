// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/?envType=daily-question&envId=2025-06-22
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.length();
        int i = 0;
        while (i < n) {
            int count = k;
            string temp;
            while (count--) {
                if (i >= n) {
                    temp += fill;
                    continue;
                }
                temp += s[i++];
            }
            res.push_back(temp);
        }
        return res;
    }
};
