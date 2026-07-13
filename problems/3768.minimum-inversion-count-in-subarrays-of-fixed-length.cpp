// @leetcode id=3768 questionId=4145 slug=minimum-inversion-count-in-subarrays-of-fixed-length lang=cpp site=leetcode.com title="Minimum Inversion Count in Subarrays of Fixed Length"
class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        // Maintain a coordinate-compressed Fenwick tree over the current
        // window's values. Sliding right removes the leftmost element
        // (subtract inversions it formed with smaller values still in the
        // window) and adds the new rightmost element (add inversions it
        // forms with larger values already present), avoiding an O(k^2)
        // recount per window.
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        auto rank = [&](int v) {
            return lower_bound(sorted.begin(), sorted.end(), v) - sorted.begin() + 1;
        };

        vector<long long> tree(m + 1, 0);
        auto update = [&](int i, long long delta) {
            for (; i <= m; i += i & (-i)) tree[i] += delta;
        };
        auto query = [&](int i) -> long long {
            long long s = 0;
            for (; i > 0; i -= i & (-i)) s += tree[i];
            return s;
        };

        long long total = 0;
        int inWindow = 0;
        for (int i = 0; i < k; i++) {
            int r = rank(nums[i]);
            total += inWindow - query(r); // count already-inserted > nums[i]
            update(r, 1);
            inWindow++;
        }

        long long best = total;
        for (int i = k; i < n; i++) {
            int leftRank = rank(nums[i - k]);
            total -= query(leftRank - 1); // count remaining in window < leaving value
            update(leftRank, -1);
            inWindow--;

            int rightRank = rank(nums[i]);
            total += inWindow - query(rightRank); // count already in window > incoming value
            update(rightRank, 1);
            inWindow++;

            best = min(best, total);
        }
        return best;
    }
};
