// 2661. First Completely Painted Row or Column -> LeetCode Daily Problem (Medium)

// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
// Return the smallest index i at which either a row or a column will be completely painted in mat.

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int,int>> mpp;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                mpp[mat[i][j]] = {i, j};
            }
        }
        vector<int> rowMark(mat.size(), 0);
        vector<int> colMark(mat[0].size(), 0);
        for (int i = 0; i < arr.size(); i++) {
            pair<int, int> pp = mpp[arr[i]];
            rowMark[pp.first]++;
            colMark[pp.second]++;
            if (rowMark[pp.first] == mat[0].size()) return i;
            if (colMark[pp.second] == mat.size()) return i;
        }
        return -1;
    }
};
