// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> res;
    const vector<string> phone = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};

    void f(int ind, string &str, const string &digits) {
        if (ind == digits.size()) {
            res.push_back(str);
            return;
        }
        for (char ch : phone[digits[ind] - '0']) {
            str.push_back(ch);
            f(ind + 1, str, digits);
            str.pop_back();
        }
    }

  public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string str;
        f(0, str, digits);
        return res;
    }
};
