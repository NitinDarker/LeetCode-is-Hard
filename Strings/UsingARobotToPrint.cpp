// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/?envType=daily-question&envId=2025-06-06
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string robotWithString(string s) {
        string paper = "";

        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 97]++;
        }

        stack<char> st; // string t
        int p = 0;      // pointer for string s

        // i pointer is for frequency array
        for (int i = 0; i < 26; i++) {
            if (p == s.length()) break;
            if (freq[i] == 0) continue;

            while (!st.empty() && st.top() <= (i + 97)) {
                paper += st.top();
                st.pop();
            }

            while (freq[i] != 0) {
                while (s[p] != (i + 97)) {
                    st.push(s[p]);
                    freq[s[p] - 97]--;
                    p++;
                }
                paper += s[p];
                freq[i]--;
                p++;
            }
        }

        while (!st.empty()) {
            paper += st.top();
            st.pop();
        }
        
        return paper;
    }
};
