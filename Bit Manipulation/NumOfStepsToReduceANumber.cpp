// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '1') {
                int n = s.length();
                int carry = 1;
                for (int i = n-1; i >= 0; i--) {
                    if (s[i] == '1') s[i] = '0';
                    else if (s[i] == '0') {
                        carry = 0;
                        s[i] = '1';
                        break;
                    } 
                }
                if (carry) {
                    string temp = "1";
                    temp += s;
                    s = temp;
                }
            } else {
                s.pop_back();
            }
            steps++;
        }    
        return steps;  
    }
};
