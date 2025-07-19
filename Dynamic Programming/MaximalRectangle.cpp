// https://leetcode.com/problems/maximal-rectangle/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Single-Pass
    int histogram(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (heights[element] * (nse - pse - 1)));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int element = st.top(); st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (heights[element] * (nse - pse - 1)));
        }
        return maxArea;
    }

  public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    prefix[i][j] = matrix[i][j] == '1' ? 1 : 0;
                    continue;
                }
                if (matrix[i][j] == '1') {
                    prefix[i][j] = 1 + prefix[i-1][j];
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, histogram(prefix[i]));
        }
        return maxi;
    }
};
