// https://leetcode.com/problems/letter-tile-possibilities/submissions/1546158583/?envType=daily-question&envId=2025-02-17
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    int backtrack(unordered_map<char, int> &mpp) {
        int res = 0;
        for (auto &ptr : mpp) {
            if (ptr.second > 0) {
                res++;
                ptr.second--;
                res += backtrack(mpp);

                // Backtrack
                ptr.second++;
            }
        }
        return res;
    }

  public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> mpp;
        for (char ch : tiles) {
            mpp[ch]++;
        }
        return backtrack(mpp);
    }
};
