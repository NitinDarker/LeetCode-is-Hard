// https://leetcode.com/problems/next-greater-element-iv/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> sge(n, -1);
        stack<int> s1, s2;
        for (int i = 0; i < n; i++) {
            while (!s2.empty() && nums[s2.top()] < nums[i]) {
                sge[s2.top()] = nums[i];
                s2.pop();
            }
            stack<int> temp;
            while (!s1.empty() && nums[s1.top()] < nums[i]) {
                temp.push(s1.top());
                s1.pop();
            }
            while (!temp.empty()) {
                s2.push(temp.top());
                temp.pop();
            }
            s1.push(i);
        }
        return sge;
    }
};
