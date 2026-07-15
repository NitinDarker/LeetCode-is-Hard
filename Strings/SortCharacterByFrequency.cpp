class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        set<pair<int, char>> st;
        for (char ch : s) {
            freq[ch]++;
        }
        for (auto &[ch, f] : freq) {
            st.insert({f, ch});
        }
        string res;
        for (auto &[f, ch] : st) {
            for (int i = 0; i < f; i++) res += ch;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
