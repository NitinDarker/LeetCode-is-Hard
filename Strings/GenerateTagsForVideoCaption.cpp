// https://leetcode.com/contest/weekly-contest-454/problems/generate-tag-for-video-caption/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isCapital(char ch) {
        return (ch >= 'A' && ch <= 'Z');
    }

  public:
    string generateTag(string caption) {
        string res = "#";
        bool capital = false;
        int i = 0;
        while (i < caption.size() && res.size() < 100) {
            if (caption[i] == ' ') {
                capital = true;
                i++;
                continue;
            }

            if (!isCapital(caption[i]) && !(caption[i] >='a' && caption[i] <= 'z')) {
                continue;
            }
            if (res.size() == 1) {
                if (isCapital(caption[i])) {
                    res += (caption[i] + 32);
                } else {
                    res += caption[i];
                }
                i++;
                capital = false;
                continue;
            }
            if (!capital && isCapital(caption[i])) {
                res += (caption[i] + 32);
            } else if (capital && !isCapital(caption[i])) {
                res += (caption[i] - 32);
                capital = false;
            } else if (capital && isCapital(caption[i])) {
                res += caption[i];
                capital = false;
            } 
            else {
                res += caption[i];
            }
            i++;
        }
        return res;
    }
};
