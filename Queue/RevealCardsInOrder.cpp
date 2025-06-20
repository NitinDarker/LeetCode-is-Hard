#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());

        queue<int> q;
        for (int ind = 0; ind < n; ind++) {
            q.push(ind);
        }

        vector<int> res(n);
        int ptr = 0;

        while (!q.empty()) {
            int idx = q.front(); // step-1
            q.pop();

            res[idx] = deck[ptr];
            ptr++;
            
            if (q.empty()) {
                break;
            }
            int next = q.front(); // step-2
            q.pop();
            q.push(next);
        }
        return res;
    }
};
