// https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        int n = s1.length();
        vector<int> map(26, -1);
        vector<int> vis(26, 0);
        for (int i = 0; i < n; i++) {
            int p = s1[i] - 'a', q = s2[i] - 'a';
            if ((map[p] == -1 && vis[q] == 1) || (map[p] != -1 && map[p] != q)) return false;
            map[p] = q;
            vis[q] = 1;
        }
        return true;
    }
};
