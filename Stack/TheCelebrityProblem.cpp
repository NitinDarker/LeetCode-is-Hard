// Time: O(n^2) and Space: O(2*n)
class Solution {
  public:
    int celebrity(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<int> IKnow(n, 0), KnowsMe(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && mat[i][j] == 1) {
                    IKnow[i]++;
                    KnowsMe[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (IKnow[i] == 0 && KnowsMe[i] == n-1) return i;
        }
        return -1;
    }
};

// Time: O(n) and Space: O(1)
class Solution {
  public:
    int celebrity(vector<vector<int>> &mat) {
        int n = mat.size();
        int top = 0, bottom = n-1;
        while (top < bottom) {
            if (mat[top][bottom] == 1) top++;
            else if (mat[bottom][top] == 1) bottom--;
            else top++, bottom--;
        }
        int celeb = top;
        if (top != bottom) return -1;
        for (int j = 0; j < n; j++) {
            if (j != celeb && mat[celeb][j] == 1) return -1;
        }
        for (int i = 0; i < n; i++) {
            if (i != celeb && mat[i][celeb] == 0) return -1;
        }
        return celeb;
    }
};
