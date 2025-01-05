/*  2381. Shifting Letters II (Daily Problem)
You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. 
For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). 
Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
Return the final string after all such shifts to s are applied.
*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = s.length();
        vector<int> load(len + 1);
        for (auto &i: shifts) {
            if (i[2] == 1) {
                load[i[1] + 1] += 1;
                load[i[0]] += -1;
            } else {
                load[i[1] + 1] += -1;
                load[i[0]] += 1;
            }
        }
        long long diff = load[len];
        for (int i = len-1; i >= 0; i--) {
            diff = diff % 26;
            int c1 = s[i] - (int)'a';
            if (diff != 0) {
                c1 = (c1 + diff + 26) % 26;
                s[i] = (char)c1 + 'a';
            }
            diff += load[i];
        }
        return s;
    }
};
