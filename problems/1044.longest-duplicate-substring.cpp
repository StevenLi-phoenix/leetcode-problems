// @leetcode id=1044 questionId=1122 slug=longest-duplicate-substring lang=cpp site=leetcode.com title="Longest Duplicate Substring"
class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        const long long MOD1 = 1000000007, MOD2 = 998244353;
        const long long BASE1 = 131, BASE2 = 137;

        vector<long long> h1(n + 1, 0), h2(n + 1, 0), p1(n + 1, 1), p2(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + s[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + s[i]) % MOD2;
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }

        auto getHash = [&](int l, int len) -> long long {
            long long r1 = (h1[l + len] - h1[l] * p1[len] % MOD1 + MOD1 * MOD1) % MOD1;
            long long r2 = (h2[l + len] - h2[l] * p2[len] % MOD2 + MOD2 * MOD2) % MOD2;
            return r1 * MOD2 + r2;
        };

        auto findDup = [&](int len) -> int {
            if (len == 0) return -1;
            unordered_set<long long> seen;
            for (int i = 0; i + len <= n; i++) {
                long long h = getHash(i, len);
                if (seen.count(h)) return i;
                seen.insert(h);
            }
            return -1;
        };

        int lo = 1, hi = n - 1, bestLen = 0, bestStart = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int start = findDup(mid);
            if (start != -1) {
                bestLen = mid;
                bestStart = start;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (bestStart == -1) return "";
        return s.substr(bestStart, bestLen);
    }
};
