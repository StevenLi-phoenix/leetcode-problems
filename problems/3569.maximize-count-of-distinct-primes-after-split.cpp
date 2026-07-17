// @leetcode id=3569 questionId=3878 slug=maximize-count-of-distinct-primes-after-split lang=cpp site=leetcode.com title="Maximize Count of Distinct Primes After Split"
class Solution {
public:
    struct SegTree {
        int n;
        vector<long long> mx, lazy;
        void init(int size) {
            n = size;
            mx.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }
        void push(int node) {
            if (lazy[node] != 0) {
                for (int c : {2 * node, 2 * node + 1}) {
                    mx[c] += lazy[node];
                    lazy[c] += lazy[node];
                }
                lazy[node] = 0;
            }
        }
        void update(int node, int l, int r, int ql, int qr, long long delta) {
            if (qr < l || r < ql) return;
            if (ql <= l && r <= qr) {
                mx[node] += delta;
                lazy[node] += delta;
                return;
            }
            push(node);
            int mid = (l + r) / 2;
            update(2 * node, l, mid, ql, qr, delta);
            update(2 * node + 1, mid + 1, r, ql, qr, delta);
            mx[node] = max(mx[2 * node], mx[2 * node + 1]);
        }
        void rangeAdd(int l, int r, long long delta) {
            if (l > r) return;
            update(1, 0, n - 1, l, r, delta);
        }
        long long globalMax() { return mx[1]; }
    };

    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int MAXV = 100001;
        vector<bool> isPrime(MAXV, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < MAXV; i++) {
            if (isPrime[i]) {
                for (long long j = (long long)i * i; j < MAXV; j += i) isPrime[j] = false;
            }
        }

        SegTree seg;
        seg.init(n - 1); // represents k = 1..n-1, tree index i -> k = i+1

        unordered_map<int, set<int>> positions;
        int D = 0;

        auto applyPrime = [&](int p, int idx, bool insert) {
            auto& s = positions[p];
            bool hadBefore = !s.empty();
            if (hadBefore) {
                int first = *s.begin(), last = *s.rbegin();
                if (first < last) seg.rangeAdd(first + 1 - 1, last - 1, -1);
            }
            if (insert) s.insert(idx);
            else s.erase(idx);
            bool hasAfter = !s.empty();
            if (hadBefore && !hasAfter) D--;
            if (!hadBefore && hasAfter) D++;
            if (hasAfter) {
                int first = *s.begin(), last = *s.rbegin();
                if (first < last) seg.rangeAdd(first + 1 - 1, last - 1, 1);
            }
            if (s.empty()) positions.erase(p);
        };

        for (int i = 0; i < n; i++) {
            if (isPrime[nums[i]]) applyPrime(nums[i], i, true);
        }

        vector<int> result;
        result.reserve(queries.size());

        for (auto& q : queries) {
            int idx = q[0], val = q[1];
            int oldVal = nums[idx];

            if (isPrime[oldVal]) applyPrime(oldVal, idx, false);
            nums[idx] = val;
            if (isPrime[val]) applyPrime(val, idx, true);

            result.push_back(D + (int)seg.globalMax());
        }

        return result;
    }
};
