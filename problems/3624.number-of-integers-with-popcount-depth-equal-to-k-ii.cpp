// @leetcode id=3624 questionId=3941 slug=number-of-integers-with-popcount-depth-equal-to-k-ii lang=cpp site=leetcode.com title="Number of Integers With Popcount-Depth Equal to K II"
class Solution {
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        // Values are at most 1e15 (< 2^50), so the popcount-depth sequence
        // collapses to 1 within a handful of steps; k is bounded to 0..5,
        // so maintain one Fenwick tree per depth value (presence bitmap)
        // to answer range-count queries and support point updates.
        int n = nums.size();
        const int MAXD = 6;

        struct Fenwick {
            vector<int> tree;
            int n;
            void init(int sz) { n = sz; tree.assign(sz + 1, 0); }
            void update(int i, int delta) {
                for (i++; i <= n; i += i & (-i)) tree[i] += delta;
            }
            int prefix(int i) {
                int s = 0;
                for (; i > 0; i -= i & (-i)) s += tree[i];
                return s;
            }
            int range(int l, int r) { return prefix(r + 1) - prefix(l); }
        };

        auto depthOf = [](long long x) -> int {
            int d = 0;
            while (x != 1) {
                x = __builtin_popcountll((unsigned long long)x);
                d++;
            }
            return d;
        };

        vector<Fenwick> fen(MAXD);
        for (int d = 0; d < MAXD; d++) fen[d].init(n);

        vector<int> curDepth(n);
        for (int j = 0; j < n; j++) {
            int d = depthOf(nums[j]);
            curDepth[j] = d;
            if (d < MAXD) fen[d].update(j, 1);
        }

        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2], k = q[3];
                ans.push_back(k < MAXD ? fen[k].range(l, r) : 0);
            } else {
                int idx = q[1];
                long long val = q[2];
                int oldD = curDepth[idx];
                if (oldD < MAXD) fen[oldD].update(idx, -1);
                int newD = depthOf(val);
                curDepth[idx] = newD;
                if (newD < MAXD) fen[newD].update(idx, 1);
            }
        }
        return ans;
    }
};
