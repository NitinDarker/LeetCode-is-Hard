// https://leetcode.com/problems/sum-of-subarray-ranges/
#include <bits/stdc++.h>
using namespace std;

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

    vector<int> nextGreater(vector<int> &nums) {
        int n = nums.size();
        vector<int> nge(n, n);
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if (!st.empty()) nge[i] = st.top();
            st.push(i);
        }
        return nge;
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

    vector<int> previousGreaterOrEqual(vector<int> &nums) {
        int n = nums.size();
        vector<int> pge(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if (!st.empty()) pge[i] = st.top();
            st.push(i);
        }
        return pge;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = nextSmaller(arr);
        vector<int> pse = previousSmallerOrEqual(arr);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (i-pse[i]) * (nse[i]-i) * 1LL * arr[i];
        }
        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = nextGreater(arr);
        vector<int> pse = previousGreaterOrEqual(arr);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (i-pse[i]) * (nse[i]-i) * 1LL * arr[i];
        }
        return sum;
    }

  public:
    int subarrayRanges(vector<int> &nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
