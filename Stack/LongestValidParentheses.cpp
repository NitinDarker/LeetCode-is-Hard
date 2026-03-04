// https://leetcode.com/problems/longest-valid-parentheses/description/
#include <bits/stdc++.h>
using namespace std;

// Extra Space for Visited Array
class Solution1 {
  public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) continue;
                int top = st.top();
                st.pop();
                vis[i] = 1;
                vis[top] = 1;
            }
        }
        int maxCnt = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                maxCnt = max(maxCnt, cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        maxCnt = max(maxCnt, cnt);
        return maxCnt;
    }
};

// Storing Last Unmatched indices
class Solution2 {
  public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        st.push(-1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) st.push(i);
                else cnt = max(cnt, i-st.top());
            }
        }
        return cnt;
    }
};

// Constant Space (Without Stack)
class Solution {
  public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int l = 0, r = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') l++;
            else r++;
            if (l == r) cnt = max(cnt, 2*r);
            else if (l < r) l = r = 0;
        }
        l = r = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == ')') r++;
            else l++;
            if (l == r) cnt = max(cnt, 2*l);
            else if (l > r) l = r = 0;
        }
        return cnt;
    }
};
