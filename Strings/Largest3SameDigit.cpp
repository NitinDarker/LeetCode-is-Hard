/* 2264. Largest 3-Same-Digit Number in String

You are given a string num representing a large integer. An integer is good if it meets the following conditions:
    It is a substring of num with length 3.
    It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note: A substring is a contiguous sequence of characters within a string.
      There may be leading zeroes in num or a good integer.
*/

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        int count = 0;
        int curr = num[0];
        string ans = "0";
        for (int i = 0; i < n; i++) {
            if (num[i] == curr) {
                count++;
            } else {
                count = 1;
                curr = num[i];
            }
            if (count == 3) {
                string str = "";
                str += num[i];
                str += num[i];
                str += num[i];
                if (str[0] >= ans[0]) ans = str;
            }
        }
        if (ans == "0") return "";
        return ans;
    }
};
