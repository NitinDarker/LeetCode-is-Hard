// https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextFreqGreater(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) freq[arr[i]]++;
        stack<int> st;
        vector<int> res(n);
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && freq[st.top()] <= freq[arr[i]]) st.pop();
            if (st.empty()) res[i] = -1;
            else res[i] = st.top();
            st.push(arr[i]);
        }
        return res;
    }
};
