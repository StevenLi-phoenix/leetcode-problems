// @leetcode id=87 questionId=87 slug=scramble-string lang=cpp site=leetcode.com title="Scramble String"
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        // memo[i][j][len]: 0 = unknown, 1 = true, 2 = false
        vector<vector<vector<char>>> memo(n, vector<vector<char>>(n, vector<char>(n + 1, 0)));

        function<bool(int, int, int)> solve = [&](int i, int j, int len) -> bool {
            char& state = memo[i][j][len];
            if (state) return state == 1;

            if (s1.compare(i, len, s2, j, len) == 0) {
                state = 1;
                return true;
            }

            int count[26] = {0};
            for (int k = 0; k < len; ++k) {
                ++count[s1[i + k] - 'a'];
                --count[s2[j + k] - 'a'];
            }
            for (int c = 0; c < 26; ++c) {
                if (count[c] != 0) {
                    state = 2;
                    return false;
                }
            }

            for (int cut = 1; cut < len; ++cut) {
                // no swap
                if (solve(i, j, cut) && solve(i + cut, j + cut, len - cut)) {
                    state = 1;
                    return true;
                }
                // swap
                if (solve(i, j + len - cut, cut) && solve(i + cut, j, len - cut)) {
                    state = 1;
                    return true;
                }
            }
            state = 2;
            return false;
        };

        return solve(0, 0, n);
    }
};
