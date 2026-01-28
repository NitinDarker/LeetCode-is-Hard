// https://leetcode.com/problems/next-greater-element-ii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            st.push(i);
        }
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if (!st.empty()) nge[i] = nums[st.top()];
            st.push(i);
        }
        return nge;
    }
};
