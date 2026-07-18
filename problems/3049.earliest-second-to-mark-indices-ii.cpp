// @leetcode id=3049 questionId=3289 slug=earliest-second-to-mark-indices-ii lang=cpp site=leetcode.com title="Earliest Second to Mark Indices II"
class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();

        vector<int> firstOcc(n + 1, -1);
        for (int t = 0; t < m; t++) {
            int idx = changeIndices[t];
            if (firstOcc[idx] == -1) firstOcc[idx] = t + 1; // 1-indexed second
        }

        vector<int> uf;
        function<int(int)> find = [&](int x) -> int {
            while (uf[x] != x) {
                uf[x] = uf[uf[x]];
                x = uf[x];
            }
            return x;
        };

        auto feasible = [&](int T) -> bool {
            long long total = 0;
            for (int i = 0; i < n; i++) total += (long long)nums[i] + 1;
            if (total <= T) return true; // no conversions needed at all

            vector<pair<int, int>> candidates; // (savings, maxAllowedJ)
            for (int i = 1; i <= n; i++) {
                if (firstOcc[i] == -1) continue;
                int savings = nums[i - 1] - 1;
                if (savings <= 0) continue;
                int numerJ = T - 1 - firstOcc[i];
                if (numerJ < 0) continue; // floor division would be negative -> ineligible
                int maxAllowedJ = numerJ / 2;
                candidates.push_back({savings, maxAllowedJ});
            }

            sort(candidates.begin(), candidates.end(), greater<pair<int,int>>());

            // slots are 0-indexed j = 0..maxSlot; internally offset by 1 so slot 0
            // isn't special-cased; index 0 in uf[] is a permanent "none available" sentinel.
            int maxSlot = n + 2;
            uf.assign(maxSlot + 2, 0);
            for (int i = 0; i <= maxSlot + 1; i++) uf[i] = i;

            long long totalSavings = 0;
            for (auto& [savings, maxJ] : candidates) {
                int cap = min(maxJ, maxSlot);
                if (cap < 0) continue;
                int slot = find(cap + 1); // +1 offset
                if (slot == 0) continue; // sentinel: no slot available
                totalSavings += savings;
                uf[slot] = slot - 1;
            }

            return (total - totalSavings) <= T;
        };

        if (!feasible(m)) return -1;

        int lo = n, hi = m, ans = m; // need at least n seconds to mark n indices
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
