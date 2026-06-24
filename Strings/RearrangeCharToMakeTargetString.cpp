class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        vector<int> tar(26, 0);
        for (char ch : target) {
            tar[ch - 'a']++;
        }

        int cnt = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (tar[i] == 0) continue;
            cnt = min(cnt, freq[i] / tar[i]);
        }
        
        return cnt;
    }
};
