// https://leetcode.com/problems/count-caesar-cipher-pairs/

class Solution {
  public:
    long long countPairs(vector<string> &words) {
        int n = words.size();
        vector<string> hash;
        unordered_map<string, int> freq;
        long long cnt = 0;
        for (string &s : words) {
            int len = s.length();
            string h = "";
            for (int i = 0; i < len-1; i++) {
               int dif = (s[i+1] - s[i] + 26) % 26;
               h += (char)(dif+'a');
            }
            hash.push_back(h);
            freq[h]++;
        }
        for (string h: hash) {
            cnt += freq[h]-1;
        }
        return cnt/2;
    }
};
