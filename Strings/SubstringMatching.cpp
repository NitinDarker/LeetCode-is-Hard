/*  3407. Substring Matching Pattern (Contest Problem - Easy)
You are given a string s and a pattern string p, where p contains exactly one '*' character.
The '*' in p can be replaced with any sequence of zero or more characters.
Return true if p can be made a substring of s, and false otherwise.
A substring is a contiguous non-empty sequence of characters within a string.
*/
class Solution {
public:
    bool hasMatch(string s, string p) {
        size_t starPos = p.find('*');
        if (starPos == std::string::npos) {
            return false;
        }
        std::string prefix = p.substr(0, starPos);
        std::string suffix = p.substr(starPos + 1);
        size_t prefixPos = s.find(prefix);
        while (prefixPos != std::string::npos) {
            size_t suffixPos = s.find(suffix, prefixPos + prefix.length());
            if (suffixPos != std::string::npos) {
                return true; // Found both prefix and suffix
            }
            prefixPos = s.find(prefix, prefixPos + 1);
        }
        return false; // No valid combination found
    }
};
// The problem is ugly, but it is clear that the code was copied from AI (shameful!).
