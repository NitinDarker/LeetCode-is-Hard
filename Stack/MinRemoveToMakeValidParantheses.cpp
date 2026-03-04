// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
#include <bits/stdc++.h>
using namespace std;

// Using Stack + Bitmap
class Solution1 {
  public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        int cnt = 0;
        stack<int> st;
        vector<int> balanced(n, 1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')' && st.empty()) {
                balanced[i] = 0;
            } else if (s[i] == ')') {
                st.pop();
            }
        }
        while (!st.empty()) {
            balanced[st.top()] = 0;
            st.pop();
        }
        string res;
        for (int i = 0; i < n; i++) {
            if (balanced[i] == 1)
                res += s[i];
        }
        return res;
    }
};

// Without extra Space (No Stack)
class Solution {
  public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        string temp;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                temp += s[i];
                cnt++;
            } else if (s[i] == ')') {
                if (cnt != 0) {
                    temp += s[i];
                    cnt--;
                }
            } else {
                temp += s[i];
            }
        }
        string res;
        cnt = 0;
        for (int i = temp.length()-1; i >= 0; i--) {
            if (temp[i] == ')') {
                res += temp[i];
                cnt++;
            } else if (temp[i] == '(') {
                if (cnt != 0) {
                    res += temp[i];
                    cnt--;
                }
            } else {
                res += temp[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
