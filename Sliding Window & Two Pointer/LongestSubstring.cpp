// Longest substring with distinct characters -> GFG Daily Problem

// Given a string s, find the length of the longest substring with all distinct characters

int longestUniqueSubstr(string &s) {
    int len = s.length();
    int maxCount = 0;
    int i = 0, j = 0;  // j is the right pointer, i is the left pointer
    unordered_set<char> mpp;
    
    while (j < len) {
        // Expand the window by adding character s[j]
        if (mpp.find(s[j]) == mpp.end()) {
            mpp.insert(s[j]);
            maxCount = max(maxCount, j - i + 1);
            j++;
        } else {
            // Shrink the window from the left
            mpp.erase(s[i]);
            i++;
        }
    }
    return maxCount;
}
