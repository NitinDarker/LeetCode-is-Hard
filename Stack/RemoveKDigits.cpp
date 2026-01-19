// https://leetcode.com/problems/remove-k-digits/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removeKdigits(string &s, int k) {
        int n = s.length();
        stack<char> st;
        for (char ch : s) {
            while (!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while (!st.empty() && k--) st.pop();
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        while (!res.empty() && res.back() == '0') res.pop_back();
        if (res.empty()) return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};
