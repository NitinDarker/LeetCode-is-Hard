// 1047. Remove All Adjacent Duplicates In String

// You are given a string s consisting of lowercase English letters. 
// A duplicate removal consists of choosing two adjacent and equal letters and removing them.
// We repeatedly make duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string result = ""; // Empty String
        int lastIndex = -1; // Tracks last index of result
        for (int i = 0; i < n; i++) {
            if (!result.empty() && result[lastIndex] == s[i]) {
                result.erase(lastIndex, 1); 
                lastIndex--;
            } else {
                result += s[i];
                lastIndex++;
            }
        }
        return result;
    }
};
