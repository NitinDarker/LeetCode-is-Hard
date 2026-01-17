// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
                int x3 = topRight[i][0], y3 = topRight[i][1];
                int x2 = bottomLeft[j][0], y2 = bottomLeft[j][1];
                int x4 = topRight[j][0], y4 = topRight[j][1];
                
                // Intersection points
                int botx = max(x1, x2), boty = max(y1, y2);
                int topx = min(x3, x4), topy = min(y3, y4);
                int w = topx - botx;
                int h = topy - boty;
                long long side = min(w, h);
                if (side < 0) side = 0;
                long long area = side * side;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
