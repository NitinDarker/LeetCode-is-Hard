// https://leetcode.com/problems/count-total-number-of-colored-cells/?envType=daily-question&envId=2025-03-05
class Solution {
public:
    long long coloredCells(long long n) {
        // S(n) = (n-1)*4 + S(n-1)
        return ((2)*(n)*(n-1)) + 1;
    }
};

// Using Recursion
class Solution2 {
public:
    long long coloredCells(long long n) {
        // S(n) = (n-1)*4 + S(n-1)
        if (n == 1) {
            // Base case
            return 1;
        }
        return coloredCells(n-1) + (long long)4*(n-1);
    }
};
