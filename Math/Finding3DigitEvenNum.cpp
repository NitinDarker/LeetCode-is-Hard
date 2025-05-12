// https://leetcode.com/problems/finding-3-digit-even-numbers/?envType=daily-question&envId=2025-05-12
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findEvenNumbers(vector<int> &digits) {
        vector<int> freq(10, 0);

        for (int &digit : digits) {
            freq[digit]++;
        }

        vector<int> res;

        for (int i = 1; i < 10; i++) {
            if (freq[i] == 0) continue;
            freq[i]--;
            for (int j = 0; j < 10; j++) {
                if (freq[j] == 0) continue;
                freq[j]--;
                for (int k = 0; k < 10; k++) {
                    if (k & 1 == 1 || freq[k] == 0) continue;
                    int num = (i * 100) + (j * 10) + k;
                    res.push_back(num);
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return res;
    }
};
