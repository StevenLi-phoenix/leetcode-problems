// @leetcode id=1593 questionId=1715 slug=split-a-string-into-the-max-number-of-unique-substrings lang=cpp site=leetcode.com title="Split a String Into the Max Number of Unique Substrings"
class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = s.size();
        unordered_set<string> used;
        int best = 0;

        function<void(int)> dfs = [&](int pos) {
            if (pos == n) {
                best = max(best, (int)used.size());
                return;
            }
            // prune: even if every remaining char becomes its own unique piece
            if ((int)used.size() + (n - pos) <= best) return;

            for (int end = pos + 1; end <= n; ++end) {
                string piece = s.substr(pos, end - pos);
                if (used.count(piece)) continue;
                used.insert(piece);
                dfs(end);
                used.erase(piece);
            }
        };

        dfs(0);
        return best;
    }
};
