// @leetcode id=1316 questionId=1244 slug=distinct-echo-substrings lang=cpp site=leetcode.com title="Distinct Echo Substrings"
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        const long long MOD1 = 1000000007, MOD2 = 1000000009;
        const long long BASE1 = 131, BASE2 = 137;

        vector<long long> h1(n + 1, 0), h2(n + 1, 0), p1(n + 1, 1), p2(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + text[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + text[i]) % MOD2;
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }

        auto getHash1 = [&](int l, int r) { // inclusive [l,r]
            long long res = (h1[r + 1] - h1[l] * p1[r - l + 1] % MOD1 + MOD1 * MOD1) % MOD1;
            return res;
        };
        auto getHash2 = [&](int l, int r) {
            long long res = (h2[r + 1] - h2[l] * p2[r - l + 1] % MOD2 + MOD2 * MOD2) % MOD2;
            return res;
        };

        unordered_set<long long> seen;

        for (int len = 2; len <= n; len += 2) {
            int half = len / 2;
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + half;
                if (getHash1(i, i + half - 1) == getHash1(j, j + half - 1) &&
                    getHash2(i, i + half - 1) == getHash2(j, j + half - 1)) {
                    long long combined = getHash1(i, i + len - 1) * MOD2 + getHash2(i, i + len - 1);
                    seen.insert(combined);
                }
            }
        }

        return (int)seen.size();
    }
};
