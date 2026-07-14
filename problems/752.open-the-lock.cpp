// @leetcode id=752 questionId=753 slug=open-the-lock lang=cpp site=leetcode.com title="Open the Lock"
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;

        unordered_set<string> visited;
        visited.insert("0000");
        queue<string> q;
        q.push("0000");
        int steps = 0;

        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                for (int pos = 0; pos < 4; pos++) {
                    for (int d = -1; d <= 1; d += 2) {
                        string next = cur;
                        int digit = (next[pos] - '0' + d + 10) % 10;
                        next[pos] = '0' + digit;
                        if (next == target) return steps;
                        if (!dead.count(next) && !visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
