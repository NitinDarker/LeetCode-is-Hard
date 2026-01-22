// https://leetcode.com/problems/sum-of-subarray-minimums/description/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
    vector<int> nextSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> previousSmallerOrEqual(vector<int> &nums) {
        int n = nums.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }

  public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = nextSmaller(arr);
        vector<int> pse = previousSmallerOrEqual(arr);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + ((i-pse[i]) * (nse[i]-i) * 1LL * arr[i]) % mod) % mod;
        }
        return sum;
    }
};
