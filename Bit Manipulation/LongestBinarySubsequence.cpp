// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/?envType=daily-question&envId=2025-06-26
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool checkIsBig(string bin, long long k) {
        // check if bin <= k
        long long num = 0;
        long long mul = 1;
        int i = bin.length() - 1;
        while (i >= 0) {
            if (mul > k) return true;
            num += (long long)((long long)(bin[i] - '0') * (long long)mul);
            mul *= 2;
            i--;
        }
        if (num <= k) return false;
        return true;
    }

  public:
    int longestSubsequence(string s, int k) {
        string res;
        int length = 0;
        int i = s.length() - 1;
        bool isBig = false;
        while (i >= 0) {
            if (s[i] == '0') {
                res = "0" + res;
                length++;
                i--;
                continue;
            }
            if (isBig) {
                i--;
                continue;
            }
            string temp = "1" + res;
            isBig = checkIsBig(temp, k);
            if (!isBig) {
                res = temp;
                length++;
            }
            i--;
        }
        return length;
    }
};
