// https://leetcode.com/problems/word-ladder/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // BFS
        while (!q.empty()) {
            auto it = q.front(); q.pop();
            string node = it.first;
            int l = it.second; 

            for (int i = 0; i < node.length(); i++) {
                string word = node;

                for (int j = 0; j < 26; j++) {
                    word[i] = j + 'a';

                    if (st.count(word) > 0) {
                        q.push({word, l+1});
                        st.erase(word);
                        if (word == endWord) return l+1;
                    }
                }
            }
        }

        return 0;
    }
};
