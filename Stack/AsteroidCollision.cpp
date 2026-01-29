// https://leetcode.com/problems/asteroid-collision/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> asteroidCollision(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0 || st.empty() || st.top() < 0) {
                st.push(arr[i]);
                continue;
            }
            while (!st.empty() && st.top() > 0 && st.top() < abs(arr[i])) st.pop();
            if (st.empty() || st.top() < 0) st.push(arr[i]);
            if (st.top() == abs(arr[i])) st.pop();
        }
        vector<int> res;
        while (!st.empty()) res.push_back(st.top()), st.pop();
        reverse(res.begin(), res.end());
        return res;
    }
};
