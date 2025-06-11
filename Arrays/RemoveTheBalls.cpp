// https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<int> colorStack, radiusStack;
        int c = 0, r = 0;
        while (c < color.size()) {
            if (!colorStack.empty() && colorStack.top() == color[c] && radiusStack.top() == radius[r]) {
                colorStack.pop();
                radiusStack.pop();
                c++; r++;
                continue;
            }
            colorStack.push(color[c++]);
            radiusStack.push(radius[r++]);
        }
        return radiusStack.size();
    }
};
