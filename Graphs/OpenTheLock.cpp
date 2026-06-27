class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis;

        if (dead.count("0000") || dead.count(target)) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        vis.insert("0000");

        // BFS
        while (!q.empty()) {
            auto [cur , len] = q.front();
            q.pop();

            if (cur == target) return len;

            for (int i = 0; i < 4; i++) {
                string code = cur;
                if (code[i] != '9') code[i] = code[i] + 1;
                else code[i] = '0';
                if (!dead.count(code) && !vis.count(code)) {
                    q.push({code, len+1});
                    vis.insert(code);
                }

                code = cur;
                if (code[i] != '0') code[i] = code[i] - 1;
                else code[i] = '9';
                if (!dead.count(code) && !vis.count(code)) {
                    q.push({code, len+1});
                    vis.insert(code);
                }
            }
        }
        return -1;
    }
};
