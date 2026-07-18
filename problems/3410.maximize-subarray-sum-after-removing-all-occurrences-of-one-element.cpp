// @leetcode id=3410 questionId=3688 slug=maximize-subarray-sum-after-removing-all-occurrences-of-one-element lang=cpp site=leetcode.com title="Maximize Subarray Sum After Removing All Occurrences of One Element"
class Solution {
public:
    struct Stats {
        long long total, maxPrefix, maxSuffix, maxSub;
    };

    static const long long NEG = LLONG_MIN / 4;

    Stats combine(const Stats& L, const Stats& R) {
        Stats res;
        res.total = L.total + R.total;
        res.maxPrefix = max(L.maxPrefix, L.total + R.maxPrefix);
        res.maxSuffix = max(R.maxSuffix, R.total + L.maxSuffix);
        res.maxSub = max({L.maxSub, R.maxSub, L.maxSuffix + R.maxPrefix});
        return res;
    }

    vector<int> nums;
    int n;
    vector<Stats> tree; // 1-indexed segment tree, size 4*n

    void build(int node, int l, int r) {
        if (l == r) {
            long long x = nums[l];
            tree[node] = Stats{x, x, x, x};
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }

    Stats query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(node * 2, l, mid, ql, qr);
        if (ql > mid) return query(node * 2 + 1, mid + 1, r, ql, qr);
        Stats left = query(node * 2, l, mid, ql, mid);
        Stats right = query(node * 2 + 1, mid + 1, r, mid + 1, qr);
        return combine(left, right);
    }

    long long maxSubarraySum(vector<int>& inputNums) {
        nums = inputNums;
        n = nums.size();
        tree.assign(4 * n, Stats{});
        build(1, 0, n - 1);

        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; i++) positions[nums[i]].push_back(i);

        long long best = tree[1].maxSub;

        for (auto& [val, pos] : positions) {
            int k = pos.size();
            if (k == n) continue; // removing would empty the array

            bool initialized = false;
            Stats acc{};

            int prevEnd = 0; // next segment starts here
            for (int i = 0; i <= k; i++) {
                int segStart = prevEnd;
                int segEnd = (i < k) ? pos[i] - 1 : n - 1; // inclusive
                if (segStart <= segEnd) {
                    Stats seg = query(1, 0, n - 1, segStart, segEnd);
                    acc = initialized ? combine(acc, seg) : seg;
                    initialized = true;
                }
                if (i < k) prevEnd = pos[i] + 1;
            }

            if (initialized) {
                best = max(best, acc.maxSub);
            }
        }

        return best;
    }
};
