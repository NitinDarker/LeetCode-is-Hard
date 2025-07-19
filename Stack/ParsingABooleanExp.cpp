/// https://leetcode.com/problems/parsing-a-boolean-expression/
class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> st;
        for (char c : e) {
            if (c == ',') continue;
            if (c != ')') st.push(c);
            else {
                unordered_set<char> s;
                while (st.top() != '(') { s.insert(st.top()); st.pop(); }
                st.pop();
                char op = st.top(); st.pop();
                if (op == '&') st.push(s.count('f') ? 'f' : 't');
                if (op == '|') st.push(s.count('t') ? 't' : 'f');
                if (op == '!') st.push(s.count('t') ? 'f' : 't');
            }
        }
        return st.top() == 't';
    }
};
