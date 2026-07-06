// @leetcode id=1397 questionId=1513 slug=find-all-good-strings lang=cpp site=leetcode.com title="Find All Good Strings"
class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        const int MOD = 1e9 + 7;
        int m = evil.size();

        vector<int> fail(m, 0);
        for (int i = 1; i < m; ++i) {
            int len = fail[i - 1];
            while (len > 0 && evil[i] != evil[len]) len = fail[len - 1];
            if (evil[i] == evil[len]) ++len;
            fail[i] = len;
        }

        vector<array<int, 26>> trans(m);
        for (int c = 0; c < 26; ++c) trans[0][c] = (evil[0] - 'a' == c) ? 1 : 0;
        for (int s = 1; s < m; ++s) {
            for (int c = 0; c < 26; ++c) {
                if (evil[s] - 'a' == c) trans[s][c] = s + 1;
                else trans[s][c] = trans[fail[s - 1]][c];
            }
        }

        vector<vector<long long>> memo(n, vector<long long>(m, -1));

        function<long long(int, int, bool, bool)> solve = [&](int pos, int state, bool lowBound, bool highBound) -> long long {
            if (state == m) return 0;
            if (pos == n) return 1;
            if (!lowBound && !highBound && memo[pos][state] != -1) return memo[pos][state];

            int lo = lowBound ? s1[pos] - 'a' : 0;
            int hi = highBound ? s2[pos] - 'a' : 25;

            long long total = 0;
            for (int c = lo; c <= hi; ++c) {
                int ns = trans[state][c];
                if (ns == m) continue;
                total += solve(pos + 1, ns, lowBound && c == lo, highBound && c == hi);
            }
            total %= MOD;

            if (!lowBound && !highBound) memo[pos][state] = total;
            return total;
        };

        return (int)solve(0, 0, true, true);
    }
};
