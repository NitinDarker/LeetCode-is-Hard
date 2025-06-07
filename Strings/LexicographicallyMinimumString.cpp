// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/?envType=daily-question&envId=2025-06-07
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string clearStars(string s) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap; // Min Heap
        vector<int> present(s.size(), 1);

        int idx = 0;
        while (idx < s.size()) {
            if (s[idx] == '*') {
                present[idx] = 0;
                int smallestInd = heap.top().second * -1;
                present[smallestInd] = 0;
                heap.pop();
            } else {
                heap.push({s[idx], -1 * idx});
            }
            idx++;
        }
        
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (present[i]) {
                res += s[i];
            }
        }
        return res;
    }
};
