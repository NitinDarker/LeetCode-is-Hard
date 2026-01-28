// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if (!st.empty()) nge[i] = nums[st.top()];
            st.push(i);
        }
        return nge;
    }
};
