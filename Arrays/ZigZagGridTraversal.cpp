// Q1. Zigzag Grid Traversal With Skip -> LeetCode Contest (Easy)

// You are given an m x n 2D array grid of positive integers.
// Your task is to traverse grid in a zigzag pattern while skipping every alternate cell.

// Zigzag pattern traversal is defined as following the below actions:
//     Start at the top-left cell (0, 0).
//     Move right within a row until the end of the row is reached.
//     Drop down to the next row, then traverse left until the beginning of the row is reached.
//     Continue alternating between right and left traversal until every row has been traversed.

// Note that you must skip every alternate cell during the traversal.

// Return an array of integers result containing, in order, the value of the cells visited during the zigzag traversal with skips.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> zigzagTraversal(vector<vector<int>> &grid) {
    if (grid.empty()) {
        return {};
    }
    int n = grid.size();
    vector<int> ans;
    int x = 0;
    if (grid[0].size() % 2 == 0) {
        x = grid[0].size() - 1;
    } else {
        x = grid[0].size() - 2;
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < grid[0].size(); j += 2) {
                ans.push_back(grid[i][j]);
            }
        } else {
            for (int j = x; j >= 0; j -= 2) {
                ans.push_back(grid[i][j]);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = zigzagTraversal(arr);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
