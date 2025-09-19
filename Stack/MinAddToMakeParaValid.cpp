// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char> st;
        int cnt = 0;
        for (char ch : s) {
            if (ch == '(') {
                st.push('(');
            } else if (st.empty()) {
                cnt++;
            } else {
                st.pop();
            }
        }
        cnt += st.size();
        return cnt;
    }
};
