// 2116. Check if a Parentheses String Can Be Valid -> LeetCode Daily Problem

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 != 0) {
            return false;
        }
        stack<int> st;
        stack<int> wildcard;
        for (int i = 0; i < s.length(); i++) {
            if (locked[i] == '0') {
                wildcard.push(i);
            } else {
                if (s[i] == '(') {
                    st.push(i);
                } else {
                    if (!st.empty()) {
                        st.pop();
                    } else if (!wildcard.empty()) {
                        wildcard.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        while (!st.empty()) {
            if (!wildcard.empty() && st.top() < wildcard.top()) {
                st.pop();
                wildcard.pop();
            } else {
                return false;
            }
        }
        if (wildcard.size() % 2 == 0) {
            return true;
        }
        return false;
    }
};
