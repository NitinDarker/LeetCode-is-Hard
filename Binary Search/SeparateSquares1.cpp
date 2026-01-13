// https://leetcode.com/problems/separate-squares-i/description/?envType=daily-question&envId=2026-01-13
#include <bits/stdc++.h>
using namespace std;

class Solution {
    double totalArea = 0;

    pair<int,int> findMaxMinY(vector<vector<int>> &squares) {
        int maxy = INT_MIN, miny = INT_MAX;
        for (vector<int> &sq : squares) {
            int y = sq[1], l = sq[2];
            maxy = max(maxy, y+l);
            miny = min(miny, y);
            
            double side = sq[2];
            totalArea += (side*side);
        }
        return {maxy, miny};
    }
    
    bool check(double cury, vector<vector<int>> &squares) {
        double bottomArea = 0;
        for (vector<int> &sq : squares) {
            double boty = sq[1], side = sq[2];
            double topy = boty+side;
            if (cury >= topy) bottomArea += (side*side);
            else if (cury > boty) bottomArea += (side*(cury-boty));
        }
        if (bottomArea >= totalArea/2.0) return true;
        else return false;
    }

  public:
    double separateSquares(vector<vector<int>> &squares) {
        int n = squares.size();
        pair<int,int> p = findMaxMinY(squares);
        double low = p.second, high = p.first;
        while (high-low >= 1e-5) {
            double mid = low + (high-low)/2.0;
            if (check(mid, squares)) high = mid;
            else low = mid;
        }
        return high;
    }
};
