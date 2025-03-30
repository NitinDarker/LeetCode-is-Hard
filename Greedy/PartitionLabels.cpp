// https://leetcode.com/problems/partition-labels/description/?envType=daily-question&envId=2025-03-30
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int, int>> mergeInterval(vector<pair<int, int>> &interval) {
        vector<pair<int, int>> merged;
        int lastMerged = -1;
        int ptr = -1;
        for (pair<int, int> p : interval) {
            if (p.first < lastMerged) {
                lastMerged = max(lastMerged, p.second);
                merged[ptr].second = lastMerged;
            } else {
                merged.push_back(p);
                lastMerged = p.second;
                ptr++;
            }
        }
        return merged;
    }

  public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mpp;
        unordered_map<char, int> count;
        for (int i = 0; i < s.length(); i++) {
            char letter = s[i];
            count[letter]++;
            if (count[letter] == 1) {
                mpp[letter] = {i, i};
                continue;
            }
            mpp[letter].second = i;
        }
        vector<pair<int, int>> interval;
        for (auto &it : mpp) {
            interval.push_back(it.second);
        }
        sort(interval.begin(), interval.end());
        vector<pair<int, int>> merged = mergeInterval(interval);

        vector<int> size;
        for (pair<int, int> p : merged) {
            int s = p.second - p.first + 1;
            size.push_back(s);
        }
        return size;
    }
};
