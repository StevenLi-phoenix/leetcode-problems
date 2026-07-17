// @leetcode id=3934 questionId=4105 slug=smallest-unique-subarray lang=cpp site=leetcode.com title="Smallest Unique Subarray"
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sa(n), rank_(n), tmp(n);
        for (int i = 0; i < n; i++) { sa[i] = i; rank_[i] = nums[i]; }

        for (int k = 1; k < n; k <<= 1) {
            auto cmp = [&](int a, int b) {
                if (rank_[a] != rank_[b]) return rank_[a] < rank_[b];
                int ra = (a + k < n) ? rank_[a + k] : -1;
                int rb = (b + k < n) ? rank_[b + k] : -1;
                return ra < rb;
            };
            sort(sa.begin(), sa.end(), cmp);

            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }
            rank_ = tmp;

            if (rank_[sa[n - 1]] == n - 1) break;
        }

        vector<int> lcp(n, 0);
        int h = 0;
        vector<int> rankOf(n);
        for (int i = 0; i < n; i++) rankOf[sa[i]] = i;

        for (int i = 0; i < n; i++) {
            if (rankOf[i] > 0) {
                int j = sa[rankOf[i] - 1];
                while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) h++;
                lcp[rankOf[i]] = h;
                if (h > 0) h--;
            } else {
                h = 0;
            }
        }

        int best = n;
        for (int r = 0; r < n; r++) {
            int pos = sa[r];
            int maxLcp = 0;
            if (r > 0) maxLcp = max(maxLcp, lcp[r]);
            if (r + 1 < n) maxLcp = max(maxLcp, lcp[r + 1]);
            int remaining = n - pos;
            if (maxLcp < remaining) {
                best = min(best, maxLcp + 1);
            }
        }

        return best;
    }
};
