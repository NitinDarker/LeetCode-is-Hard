// https://leetcode.com/problems/magic-squares-in-grid/
class Solution {
private:
    bool isMagic(const vector<vector<int>>& grid, int r, int c) {
        int seen[10] = {0};

        for (int i = r; i < r + 3; ++i) {
            for (int j = c; j < c + 3; ++j) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || seen[val]) return false;
                seen[val] = 1;
            }
        }

        // Row 1
        if (grid[r][c] + grid[r][c + 1] + grid[r][c + 2] != 15) return false;
        // Row 3
        if (grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] != 15) return false;

        // Col 1
        if (grid[r][c] + grid[r + 1][c] + grid[r + 2][c] != 15) return false;
        // Col 3
        if (grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] != 15) return false;

        // Diagonal 1 (Top-Left to Bottom-Right)
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15) return false;
        // Diagonal 2 (Top-Right to Bottom-Left)
        if (grid[r + 2][c] + grid[r + 1][c + 1] + grid[r][c + 2] != 15) return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m < 3 || n < 3) return 0;

        int count = 0;
        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                // Optimization: The center of a 3x3 magic square (1-9) MUST be 5.
                // The center is at grid[i+1][j+1].
                if (grid[i + 1][j + 1] != 5) continue;

                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
