// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2025-03-11
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    bool occurence(string s, int l, int r) {
        unordered_set<char> ss = {'a', 'b', 'c'};
        int occa = 0; // Occurence of a
        int occb = 0; // Occurence of b
        int occc = 0; // Occurence of c
        for (int i = l; i <= r; i++) {
            if (s[i] == 'a') occa++; 
            if (s[i] == 'b') occb++; 
            if (s[i] == 'c') occc++; 
        }
        if (occa && occb && occc) return true;
        return false;
    }

  public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int res = 0;
        vector<int> count(26, 0);

        for (int r = 0; r < s.length(); r++) {
            count[s[r] - 'a']++;
            while (count[0] && count[1] && count[2]) {
                res += (s.length() - r);
                count[s[l] - 'a']--;
                l++;
            }
        }
        return res;
    }
};
