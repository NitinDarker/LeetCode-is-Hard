// https://www.geeksforgeeks.org/problems/longest-subarray-length--202010/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n, n) , pge(n, -1);

        // Next-Greater element
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous-Greater element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pge[i] = st.top();
            }
            st.push(i);
        }

        int maxSize = 0;
        for (int i = 0; i < n; i++) {
            int curSize = nge[i] - pge[i] - 1;
            if (curSize >= arr[i]) {
                maxSize = max(maxSize, curSize);
            }
        }
        return maxSize;
    }
};
