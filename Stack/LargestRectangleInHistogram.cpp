// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>
using namespace std;

// O(5N)
class Solution {
    vector<int> findNextSmallerElement(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> findPreviousSmallerElement(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n, -1);
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return pse;
    }

  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> nse = findNextSmallerElement(heights);
        vector<int> pse = findPreviousSmallerElement(heights);
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = heights[i] * ((nse[i]-1) - (pse[i]+1) + 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

// Single-pass 
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (heights[element] * (nse-pse-1)));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int element = st.top(); st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (heights[element] * (nse-pse-1)));
        }
        return maxArea;
    }
};
