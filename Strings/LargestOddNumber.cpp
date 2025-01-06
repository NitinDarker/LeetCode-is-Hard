/* 1903. Largest Odd Number in String

You are given a string num, representing a large integer. 
Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.
*/

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int ind = n;
        for (int i = n-1; i >= 0; i--) {
            if (num[i] % 2 != 0) {
                ind = i;
                break;
            } 
        }
        if (ind == n) return "";
        string ans = "";
        for (int i = 0; i <= ind; i++) {
            ans += num[i];
        }
        return ans;
    }
};
