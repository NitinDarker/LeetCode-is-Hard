// https://leetcode.com/problems/word-ladder/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        int len = beginWord.length();
        unordered_set<string> words;
        for (string s : wordList) {
            words.insert(s);
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            string cur = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (cur == endWord) {
                return dist;
            }
            for (int i = 0; i < len; i++) {
                char ch = 'a';
                string newWord = cur;
                while (ch <= 'z') {
                    newWord[i] = ch;
                    if (words.count(newWord) != 0) {
                        q.push({newWord, dist+1});
                        words.erase(newWord);
                    }
                    ch++;
                }
            }
        }
        return 0;
    }
};
