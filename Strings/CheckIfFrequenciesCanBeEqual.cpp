// https://www.geeksforgeeks.org/problems/check-frequencies4211/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool sameFreq(string &s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        unordered_map<int, int> mpp; // frequency of frequencies
        for (auto it : freq) {
            mpp[it.second]++;
        }

        if (mpp.size() > 2) return false;
        if (mpp.size() == 1) return true;

        int a = -1, b = -1;
        for (auto it : mpp) {
            if (a == -1) a = it.first;
            else b = it.first;
        }
        
        if (a == 1 || b == 1) return true;
        if (mpp[a] == 1 && (a-b) == 1) return true;
        else if (mpp[b] == 1 && (b-a) == 1) return true; 
        return false;
    }
};

int main() {
    Solution *s = new Solution;
    string str = "xxyyz";
    cout << s->sameFreq(str);
}
