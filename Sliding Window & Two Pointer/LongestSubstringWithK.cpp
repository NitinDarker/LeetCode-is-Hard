/// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        unordered_map<char, int> freq;
        int maxLength = -1;
        int i = 0, j = 0;
        while (j < n) {
            freq[s[j]]++;
            if (freq.size() < k) {
                j++;
            } else if (freq.size() == k) {
                maxLength = max(maxLength, j-i+1);
                j++;
            } else {
                freq[s[i]]--;
                if (freq[s[i]] == 0) freq.erase(s[i]);
                i++;
                freq[s[j]]--; // Counter Measure
            }
            
        }
        return maxLength;
    }
};
