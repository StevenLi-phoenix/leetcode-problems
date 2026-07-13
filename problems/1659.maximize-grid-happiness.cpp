// @leetcode id=1659 questionId=1778 slug=maximize-grid-happiness lang=cpp site=leetcode.com title="Maximize Grid Happiness"
class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        // Broken-profile bitmask DP: mask holds the last n placement
        // decisions (base-3 digit per cell type). Its oldest digit is the
        // cell directly above the current one; its newest digit is the
        // cell immediately to the left (when not at a row start).
        if (n > m) swap(m, n); // keep the smaller dimension as the mask width

        int total = m * n;
        vector<int> pow3(n + 1);
        pow3[0] = 1;
        for (int i = 1; i <= n; i++) pow3[i] = pow3[i - 1] * 3;

        int maskCount = pow3[n];
        int maxIntro = introvertsCount, maxExtro = extrovertsCount;
        vector<vector<vector<vector<int>>>> memo(
            total + 1, vector<vector<vector<int>>>(
                maskCount, vector<vector<int>>(
                    maxIntro + 1, vector<int>(maxExtro + 1, INT_MIN))));

        function<int(int, int, int, int)> solve = [&](int idx, int mask, int introLeft, int extroLeft) -> int {
            if (idx == total) return 0;
            int& memoRef = memo[idx][mask][introLeft][extroLeft];
            if (memoRef != INT_MIN) return memoRef;

            int c = idx % n;
            int up = mask / pow3[n - 1] % 3;
            int left = (c == 0) ? 0 : (mask % 3);

            auto delta = [](int t) { return t == 1 ? -30 : (t == 2 ? 20 : 0); };
            auto base = [](int t) { return t == 1 ? 120 : (t == 2 ? 40 : 0); };
            auto edge = [&](int t, int other) {
                return (t == 0 || other == 0) ? 0 : delta(t) + delta(other);
            };

            int best = 0; // option t=0 (empty)
            {
                int newMask = (mask * 3 + 0) % maskCount;
                best = solve(idx + 1, newMask, introLeft, extroLeft);
            }
            if (introLeft > 0) {
                int gain = base(1) + edge(1, up) + edge(1, left);
                int newMask = (mask * 3 + 1) % maskCount;
                best = max(best, gain + solve(idx + 1, newMask, introLeft - 1, extroLeft));
            }
            if (extroLeft > 0) {
                int gain = base(2) + edge(2, up) + edge(2, left);
                int newMask = (mask * 3 + 2) % maskCount;
                best = max(best, gain + solve(idx + 1, newMask, introLeft, extroLeft - 1));
            }

            memoRef = best;
            return best;
        };

        return solve(0, 0, introvertsCount, extrovertsCount);
    }
};
