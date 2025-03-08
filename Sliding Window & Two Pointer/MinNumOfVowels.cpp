// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int maxVowels(string s, int k) {
        int n = s.length();
        unordered_set<char> ss = {'a', 'e', 'i', 'o', 'u'};

        int l = 0, r = k;
        int currCount = 0;
        for (int i = l; i < r; i++) {
            if (ss.find(s[i]) != ss.end()) currCount++;
        }
        int maxCount = currCount;

        while (r != n) {
            if (ss.find(s[l]) != ss.end()) currCount--;
            if (ss.find(s[r]) != ss.end()) currCount++;
            l++;
            r++;
            maxCount = max(maxCount, currCount);
        }
        return maxCount;
    }
};
