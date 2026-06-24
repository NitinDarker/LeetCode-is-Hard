class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        for (char ch : chars) {
            freq[ch - 'a']++;
        }

        int cnt = 0;
        for (string s : words) {
            vector<int> f(26, 0);
            bool good = true;
            for (char ch : s) {
                f[ch - 'a']++;
                if (f[ch - 'a'] > freq[ch - 'a']) {
                    good = false;
                    break;
                }
            }
            if (good) cnt += s.length();
        }
        return cnt;
    }
};
