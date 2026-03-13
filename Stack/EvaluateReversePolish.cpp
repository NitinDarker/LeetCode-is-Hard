// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (string &s : tokens) {
            if (s == "+" || s == "/" || s == "*" || s == "-") {
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();
                if (s == "+") st.push(left+right);
                else if (s == "-") st.push(left-right);
                else if (s == "*") st.push(left*right);
                else st.push(left/right);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
