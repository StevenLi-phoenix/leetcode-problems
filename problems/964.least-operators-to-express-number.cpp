// @leetcode id=964 questionId=1004 slug=least-operators-to-express-number lang=cpp site=leetcode.com title="Least Operators to Express Number"
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        // Decompose target in base x. At digit position k, one copy of x^k
        // costs levelCost(k) operators to build-and-attach: k for k>=1 (k-1
        // multiplications plus 1 connecting +/-), or 2 for k=0 (x/x plus a
        // connector). Track a carry (borrowing x^k units from position k+1)
        // via 2-state DP, then drop the leading connector at the very end.
        vector<long long> digits;
        long long t = target;
        while (t > 0) { digits.push_back(t % x); t /= x; }
        int m = digits.size() - 1;

        auto levelCost = [&](int k) -> long long { return k == 0 ? 2 : k; };

        const long long INF = LLONG_MAX / 4;
        long long dp0 = 0, dp1 = INF;
        for (int k = 0; k <= m; k++) {
            long long cost = levelCost(k);
            long long nd0 = INF, nd1 = INF;

            long long s0 = digits[k];
            if (s0 < x) nd0 = min(nd0, dp0 + s0 * cost);
            nd1 = min(nd1, dp0 + (x - s0) * cost);

            if (dp1 < INF) {
                long long s1 = digits[k] + 1;
                if (s1 < x) nd0 = min(nd0, dp1 + s1 * cost);
                nd1 = min(nd1, dp1 + (x - s1) * cost);
            }
            dp0 = nd0;
            dp1 = nd1;
        }

        long long ans = dp0;
        if (dp1 < INF) ans = min(ans, dp1 + levelCost(m + 1));
        return (int)(ans - 1);
    }
};
