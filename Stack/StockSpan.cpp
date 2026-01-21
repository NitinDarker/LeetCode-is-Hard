// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> previousGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> pge(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) pge[i] = st.top();
            st.push(i);
        }
        return pge;
    }

  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge = previousGreater(arr);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = i - pge[i];
        }
        return res;
    }
};
