// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=daily-question&envId=2025-03-08
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int minimumRecolors(string blocks, int k) {
        // Using sliding window
        int n = blocks.length();
        int l = 0, r = k-1;
        
        int currMin = 0;
        for (int i = l; i <= r; i++) {
            if (blocks[i] == 'W') {
                currMin++;
            }
        }
    
        int mini = currMin;
        while (r < n-1) {
            if (blocks[l] == 'W') currMin--;
            l++;
            r++;
            if (blocks[r] == 'W') currMin++;
            mini = min(mini, currMin);
        }
        return mini;
    }
};

// Inefficent but first thought
class Solution2 {
    // Calculating white num every time is redundant
    // Defeats the purpose of sliding window
    int whiteNum(string s, int l, int r) {
        int count = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] == 'W') {
                count++;
            }
        }
        return count;
    }

  public:
    int minimumRecolors(string blocks, int k) {
        // Using sliding window
        int n = blocks.length();
        int l = 0, r = k-1;
        int mini = INT_MAX;
        while (r < n) {
            int currMin = whiteNum(blocks, l, r);
            mini = min(mini, currMin);
            l++;
            r++;
        }
        return mini;
    }
};
