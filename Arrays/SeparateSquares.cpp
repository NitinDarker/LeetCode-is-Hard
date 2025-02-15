// https://leetcode.com/problems/separate-squares-i/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    double calculateArea(double x, double y) {
        return x * y;
    }

    double minY(vector<vector<int>> &arr) {
        double mini = INT_MAX;
        for (vector<int> &sub : arr) {
            mini = min(mini, (double)sub[1]);
        }
        return mini;
    }

    double maxY(vector<vector<int>> &arr) {
        double maxi = 0;
        for (vector<int> &sub : arr) {
            maxi = max(maxi, (double)(sub[1] + sub[2]));
        }
        return maxi;
    }

    double checkTopArea(vector<vector<int>> &arr, double mid) {
        double area = 0;
        for (vector<int> &sub : arr) {
            if (mid >= sub[1] + sub[2]) continue;  // Fully below
            double x = (double)sub[2];
            double y = min(sub[1] + sub[2] - mid, (double)sub[2]);
            area += calculateArea(x, y);
        }
        return area;
    }

    double checkBottomArea(vector<vector<int>> &arr, double mid) {
        double area = 0;
        for (vector<int> &sub : arr) {
            if (mid <= sub[1]) continue;  // Fully above
            double x = (double)sub[2];
            double y = min(mid - sub[1], (double)sub[2]);
            area += calculateArea(x, y);
        }
        return area;
    }

  public:
    double separateSquares(vector<vector<int>> &squares) {
        double l = minY(squares);
        double r = maxY(squares);
        double ans = r; 

        while ((r - l) > 1e-6) {  // Precision-based binary search
            double mid = (l + r) / 2.0;
            double topArea = checkTopArea(squares, mid);
            double bottomArea = checkBottomArea(squares, mid);

            if (topArea > bottomArea) {
                l = mid;  // Move up
            } else {
                ans = mid; // Store best possible answer
                r = mid;  // Move down
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> arr = {{0,0,1}, {2,2,1}};
    Solution *obj = new Solution();
    cout << obj->separateSquares(arr) << endl;
    return 0;
}
