class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        stack<string> st;
        string word;
        for (char ch : s) {
            if (ch == ' ') {
                if (word != "") st.push(word);
                word = "";
                continue;
            }
            word += ch;
        }
        if (word != "") st.push(word);
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty()) res += ' ';
        }
        return res;
    }
};
