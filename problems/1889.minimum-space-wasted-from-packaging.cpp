// @leetcode id=1889 questionId=2018 slug=minimum-space-wasted-from-packaging lang=cpp site=leetcode.com title="Minimum Space Wasted From Packaging"
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        const long long MOD = 1'000'000'007;
        int n = packages.size();
        vector<int> pkgs = packages;
        sort(pkgs.begin(), pkgs.end());

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + pkgs[i];

        long long totalPkgSize = prefix[n];
        long long best = -1;

        for (auto& supplierBoxes : boxes) {
            vector<int> b = supplierBoxes;
            sort(b.begin(), b.end());
            if (b.back() < pkgs.back()) continue; // can't fit the largest package

            long long usedBoxSpace = 0;
            int idx = 0;
            for (int boxSize : b) {
                int hi = upper_bound(pkgs.begin(), pkgs.end(), boxSize) - pkgs.begin();
                if (hi <= idx) continue;
                usedBoxSpace += (long long)boxSize * (hi - idx);
                idx = hi;
            }
            if (idx < n) continue; // shouldn't happen given the largest-box check, but guard anyway

            long long wasted = usedBoxSpace - totalPkgSize;
            if (best == -1 || wasted < best) best = wasted;
        }
        return best == -1 ? -1 : (int)(best % MOD);
    }
};
