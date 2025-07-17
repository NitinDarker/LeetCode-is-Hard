/// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        vector<int> arr;
        for (int ele : freq) {
            if (ele != 0) arr.push_back(ele);
        }
        sort(arr.begin(), arr.end(), [](int &a, int &b) { return a > b; });
        int mul = 1, map = 0;
        int pushes = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) break;
            pushes += (arr[i] * mul);
            map++;
            if (map % 8 == 0) mul++;
        }
        return pushes;
    }
};
