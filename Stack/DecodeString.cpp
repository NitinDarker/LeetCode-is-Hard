https://leetcode.com/problems/decode-string/

class Solution {
  public:
    string decodeString(string s) {
        int num = 0;
        string cur = "";
        stack<pair<int,string>> st;
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                num = num * 10 + (ch-'0');
            } else if (ch == '[') {
                st.push({num, cur});
                num = 0;
                cur = "";
            } else if (ch == ']') {
                int cnt = st.top().first;
                string prev = st.top().second;
                string temp = "";
                while (cnt--) temp += cur;
                cur = prev + temp;
                st.pop();
            } else {
                cur += ch;
            }
        }
        return cur;
    }
};
