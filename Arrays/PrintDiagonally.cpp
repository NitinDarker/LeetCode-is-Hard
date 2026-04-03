// https://www.geeksforgeeks.org/problems/print-diagonally4331/1
class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> res;
        for (int k = 0; k < 2*n-1; k++) {
            int i = (k < n) ? 0 : k - n + 1;
            int j = (k < n) ? k : n - 1;
            while (i < n && j >= 0) {
                res.push_back(mat[i][j]);
                i++;
                j--;
            }
        }
        return res;
    }
};
