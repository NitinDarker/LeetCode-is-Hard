/// https://leetcode.com/problems/generate-parentheses/description/?envType=problem-list-v2&envId=dynamic-programming
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> res;

    void f(int l, int r, string& str) {
        if (l == 0 && r == 0) {
            res.push_back(str);
            return;
        }
        if (l > 0) {
            str.push_back('(');
            f(l - 1, r, str);
            str.pop_back();
        }
        if (r > l) {
            str.push_back(')');
            f(l, r - 1, str);
            str.pop_back();
        }
    }

  public:
    vector<string> generateParenthesis(int n) {
        string str;
        f(n, n, str);
        return res;
    }
};
