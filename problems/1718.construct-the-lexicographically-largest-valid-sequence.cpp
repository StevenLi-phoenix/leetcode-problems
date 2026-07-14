// @leetcode id=1718 questionId=1819 slug=construct-the-lexicographically-largest-valid-sequence lang=cpp site=leetcode.com title="Construct the Lexicographically Largest Valid Sequence"
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int len = 2 * n - 1;
        vector<int> result(len, 0);
        vector<bool> used(n + 1, false);

        function<bool(int)> backtrack = [&](int pos) -> bool {
            if (pos == len) return true;
            if (result[pos] != 0) return backtrack(pos + 1);
            for (int v = n; v >= 1; v--) {
                if (used[v]) continue;
                if (v == 1) {
                    result[pos] = 1;
                    used[1] = true;
                    if (backtrack(pos + 1)) return true;
                    used[1] = false;
                    result[pos] = 0;
                } else {
                    int other = pos + v;
                    if (other < len && result[other] == 0) {
                        result[pos] = v;
                        result[other] = v;
                        used[v] = true;
                        if (backtrack(pos + 1)) return true;
                        used[v] = false;
                        result[pos] = 0;
                        result[other] = 0;
                    }
                }
            }
            return false;
        };

        backtrack(0);
        return result;
    }
};
