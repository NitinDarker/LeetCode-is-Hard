// https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isUpper(char ch) {
        return (ch >= 'A' && ch <= 'Z');
    }

  public:
    string caseSort(string &s) {
        vector<int> upper, lower;
        for (char ch : s) {
            if (isUpper(ch)) upper.push_back(ch);
            else lower.push_back(ch);
        }
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());

        int l = 0; // Lower pointer
        int u = 0; // Upper pointer

        string res;
        for (char ch : s) {
            if (isupper(ch)) {
                res += upper[u++];
            } else {
                res += lower[l++];
            }
        }
        return res;
    }
};
