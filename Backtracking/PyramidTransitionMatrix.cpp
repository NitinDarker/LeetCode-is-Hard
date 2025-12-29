// https://leetcode.com/problems/pyramid-transition-matrix/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, bool> memo;

    bool f(string &cur, string &next, int idx, unordered_map<string, vector<char>> &mpp) {
        if (cur.length() == 1) return true;
        string key = cur + "_" + next + "_" + to_string(idx);
        if (memo.count(key) > 0) return memo[key];
        if (idx == cur.length()-1) {
            string above = "";
            return memo[key] = f(next, above, 0, mpp);
        }
        string pair = cur.substr(idx, 2);
        if (mpp.find(pair) == mpp.end()) return false;
        for (char &ch : mpp[pair]) {
            next.push_back(ch);
            if (f(cur, next, idx+1, mpp)) return true;
            next.pop_back();
        }
        return memo[key] = false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = allowed.size();
        unordered_map<string, vector<char>> mpp;
        for (int i = 0; i < n; i++) {
            string bottom = allowed[i].substr(0, 2);
            char top = allowed[i][2];
            mpp[bottom].push_back(top);
        }
        string next = "";
        return f(bottom, next, 0, mpp);
    }
};
