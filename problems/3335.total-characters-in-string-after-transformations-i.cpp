// @leetcode id=3335 questionId=3629 slug=total-characters-in-string-after-transformations-i lang=cpp site=leetcode.com title="Total Characters in String After Transformations I"
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const long long MOD = 1e9 + 7;
        vector<long long> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        for (int step = 0; step < t; step++) {
            vector<long long> next(26, 0);
            for (int c = 0; c < 25; c++) {
                next[c + 1] = (next[c + 1] + cnt[c]) % MOD;
            }
            next[0] = (next[0] + cnt[25]) % MOD;
            next[1] = (next[1] + cnt[25]) % MOD;
            cnt = next;
        }

        long long total = 0;
        for (long long c : cnt) total = (total + c) % MOD;
        return (int)total;
    }
};
