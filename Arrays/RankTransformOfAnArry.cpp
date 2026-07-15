#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        int n = arr.size();
        set<int> st;
        unordered_map<int, vector<int>> idx;
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            st.insert(arr[i]);
            idx[arr[i]].push_back(i);
        }

        int rank = 1;
        for (int num : st) {
            for (int i : idx[num]) {
                res[i] = rank;
            }
            rank++;
        }
        return res;
    }
};
