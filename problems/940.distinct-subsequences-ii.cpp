// @leetcode id=940 questionId=977 slug=distinct-subsequences-ii lang=cpp site=leetcode.com title="Distinct Subsequences II"
class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;
        vector<long long> last(26, 0);
        long long total = 0;

        for (char c : s) {
            int idx = c - 'a';
            long long newTotal = (2 * total + 1) % MOD;
            newTotal = (newTotal - last[idx] + MOD) % MOD;
            last[idx] = (total + 1) % MOD;
            total = newTotal;
        }

        return (int)total;
    }
};
