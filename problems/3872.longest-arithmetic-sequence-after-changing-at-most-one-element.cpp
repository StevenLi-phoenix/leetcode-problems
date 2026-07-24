// @leetcode id=3872 questionId=4230 slug=longest-arithmetic-sequence-after-changing-at-most-one-element lang=cpp site=leetcode.com title="Longest Arithmetic Sequence After Changing At Most One Element"
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<long long> diff(n, 0);
        for (int i = 1; i < n; i++) diff[i] = nums[i] - nums[i - 1];

        vector<int> dp0(n, 1);
        if (n > 1) dp0[1] = 2;
        for (int i = 2; i < n; i++) {
            dp0[i] = (diff[i] == diff[i - 1]) ? dp0[i - 1] + 1 : 2;
        }

        // dp0Suffix[i]: longest real (0-change) run starting at i, extending right.
        vector<int> dp0Suffix(n, 1);
        if (n > 1) dp0Suffix[n - 2] = 2;
        for (int i = n - 3; i >= 0; i--) {
            dp0Suffix[i] = (diff[i + 1] == diff[i + 2]) ? dp0Suffix[i + 1] + 1 : 2;
        }

        int ans = 1;
        for (int i = 0; i < n; i++) ans = max(ans, dp0[i]);
        // terminal candidate: change exactly at position i (rightmost of window), freely chosen
        for (int i = 1; i < n; i++) ans = max(ans, dp0[i - 1] + 1);
        // terminal candidate: change exactly at position i (leftmost of window), freely chosen
        for (int i = 0; i < n - 1; i++) ans = max(ans, dp0Suffix[i + 1] + 1);

        // M1[i]: up to 2 (difference -> best length) entries for a run ending
        // at real position i, using exactly one change strictly before i.
        vector<pair<long long, int>> prevM1; // represents M1[i-1]

        for (int i = 2; i < n; i++) {
            vector<pair<long long, int>> newM1;

            auto addOrUpdate = [&](long long key, int val) {
                for (auto& kv : newM1) {
                    if (kv.first == key) {
                        kv.second = max(kv.second, val);
                        return;
                    }
                }
                newM1.push_back({key, val});
            };

            // continuation: extend prevM1 entries that match diff[i]
            for (auto& kv : prevM1) {
                if (kv.first == diff[i]) {
                    addOrUpdate(kv.first, kv.second + 1);
                }
            }

            // bridge: change exactly at position i-1, connecting base=i-2 and i.
            // Variant 1: inherit the full established chain ending at base (its
            // natural difference diff[base]); only meaningful when base>=1.
            int base = i - 2;
            if (base >= 1) {
                long long neededDiff = diff[base];
                if ((long long)(nums[i] - nums[base]) == 2 * neededDiff) {
                    addOrUpdate(neededDiff, dp0[base] + 2);
                }
            }
            // Variant 2: treat position base as a fresh standalone anchor
            // (ignore any history before it), free choice of bridging difference.
            if ((nums[i] - nums[base]) % 2 == 0) {
                long long d = (nums[i] - nums[base]) / 2;
                addOrUpdate(d, 3);
            }

            for (auto& kv : newM1) ans = max(ans, kv.second);
            prevM1 = move(newM1);
        }

        return ans;
    }
};
