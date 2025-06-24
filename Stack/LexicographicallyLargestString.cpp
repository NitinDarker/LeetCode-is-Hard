// https://www.geeksforgeeks.org/problems/lexicographically-largest-string-after-deleting-k-characters/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string maxSubseq(string &s, int k) {
        int n = s.length();
        int finalLength = n-k;
        stack<char> st;
        for (char ch : s) {   
            while ((k > 0) && !st.empty() && (st.top() < ch)) {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res.substr(0, finalLength);
    }
};

// Using Vector as stack
class Solution {
  public:
    string maxSubseq(string &s, int k) {
        int n = s.length();
        int finalLength = n-k;
        vector<char> st;
        for (char ch : s) {   
            while ((k > 0) && !st.empty() && (st.back() < ch)) {
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }
        string res;
        for (int i = 0; i < finalLength; i++) {
            res += st[i];
        }
        return res;
    }
};
