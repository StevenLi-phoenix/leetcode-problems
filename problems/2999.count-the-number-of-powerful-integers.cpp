// @leetcode id=2999 questionId=3243 slug=count-the-number-of-powerful-integers lang=cpp site=leetcode.com title="Count the Number of Powerful Integers"
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return count(finish, limit, s) - count(start - 1, limit, s);
    }

private:
    static long long ipow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result *= base;
            base *= base;
            exp >>= 1;
        }
        return result;
    }

    // number of prefixes of length p (digits <= limit, no leading zero) such that
    // prefix + s <= X, where X has exactly p + s.size() digits.
    static long long countPrefixes(const string& x, const string& s, int limit, int p) {
        long long count = 0;
        for (int i = 0; i < p; ++i) {
            int lo = (i == 0) ? 1 : 0;
            int xi = x[i] - '0';
            int hi = min(limit, xi - 1);
            if (hi >= lo) {
                long long ways = hi - lo + 1;
                ways *= ipow(limit + 1, p - i - 1);
                count += ways;
            }
            if (xi > limit) return count;
        }
        string xSuffix = x.substr(p, s.size());
        if (s <= xSuffix) count += 1;
        return count;
    }

    static long long count(long long x, int limit, const string& s) {
        if (x <= 0) return 0;
        string sx = to_string(x);
        int n = sx.size();
        int m = s.size();
        if (n < m) return 0;
        long long ans = 0;
        for (int len = m; len < n; ++len) {
            int p = len - m;
            if (p == 0) {
                ans += 1;
            } else {
                ans += (long long)limit * ipow(limit + 1, p - 1);
            }
        }
        ans += countPrefixes(sx, s, limit, n - m);
        return ans;
    }
};
