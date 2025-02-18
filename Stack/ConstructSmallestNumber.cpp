// https://leetcode.com/problems/construct-smallest-number-from-di-string/?envType=daily-question&envId=2025-02-18
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        int counter = 1;
        string str = "";
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            st.push(counter++);
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) {
                    str += to_string(st.top());
                    st.pop();
                }
            }
        }
        return str;
    }
};
