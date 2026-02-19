// https://leetcode.com/problems/count-binary-substrings/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int zeroCnt = 0, oneCnt = 0;
        int res = 0;
        int i = 0;
        while (i < n) {
            zeroCnt = 0;
            while (i < n && s[i] == '0') zeroCnt++, i++;
            res += min(zeroCnt, oneCnt);
            oneCnt = 0;
            while (i < n && s[i] == '1') oneCnt++, i++;
            res += min(zeroCnt, oneCnt);
        }
        return res;
    }
};
