// @leetcode id=3762 questionId=4022 slug=minimum-operations-to-equalize-subarrays lang=cpp site=leetcode.com title="Minimum Operations to Equalize Subarrays"
class Solution {
public:
    int n;
    vector<long long> q;
    vector<vector<long long>> treeVals, treePrefix;
    vector<vector<int>> sparseMin, sparseMax;
    vector<int> logTable;

    void build(int node, int lo, int hi) {
        if (lo == hi) {
            treeVals[node] = {q[lo]};
        } else {
            int mid = (lo + hi) / 2;
            build(2 * node, lo, mid);
            build(2 * node + 1, mid + 1, hi);
            treeVals[node].resize(hi - lo + 1);
            merge(treeVals[2*node].begin(), treeVals[2*node].end(),
                  treeVals[2*node+1].begin(), treeVals[2*node+1].end(),
                  treeVals[node].begin());
        }
        treePrefix[node].resize(treeVals[node].size() + 1, 0);
        for (size_t i = 0; i < treeVals[node].size(); i++) {
            treePrefix[node][i+1] = treePrefix[node][i] + treeVals[node][i];
        }
    }

    // returns {count, sum} of elements <= X within node range intersect [l,r]
    pair<long long,long long> queryNode(int node, int lo, int hi, int l, int r, long long X) {
        if (r < lo || hi < l) return {0, 0};
        if (l <= lo && hi <= r) {
            int idx = upper_bound(treeVals[node].begin(), treeVals[node].end(), X) - treeVals[node].begin();
            return {idx, treePrefix[node][idx]};
        }
        int mid = (lo + hi) / 2;
        auto a = queryNode(2*node, lo, mid, l, r, X);
        auto b = queryNode(2*node+1, mid+1, hi, l, r, X);
        return {a.first + b.first, a.second + b.second};
    }

    int rmqMin(int l, int r) {
        int j = logTable[r - l + 1];
        return min(sparseMin[j][l], sparseMin[j][r - (1 << j) + 1]);
    }
    int rmqMax(int l, int r) {
        int j = logTable[r - l + 1];
        return max(sparseMax[j][l], sparseMax[j][r - (1 << j) + 1]);
    }

    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        q.resize(n);
        vector<int> rem(n);
        for (int i = 0; i < n; i++) {
            q[i] = nums[i] / k;
            rem[i] = nums[i] % k;
        }

        logTable.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) logTable[i] = logTable[i/2] + 1;
        int LOG = logTable[n] + 1;
        sparseMin.assign(LOG, vector<int>(n));
        sparseMax.assign(LOG, vector<int>(n));
        sparseMin[0] = rem; sparseMax[0] = rem;
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                sparseMin[j][i] = min(sparseMin[j-1][i], sparseMin[j-1][i + (1 << (j-1))]);
                sparseMax[j][i] = max(sparseMax[j-1][i], sparseMax[j-1][i + (1 << (j-1))]);
            }
        }

        treeVals.assign(4 * n, {});
        treePrefix.assign(4 * n, {});
        build(1, 0, n - 1);

        vector<long long> answer;
        for (auto& query : queries) {
            int l = query[0], r = query[1];
            if (rmqMin(l, r) != rmqMax(l, r)) {
                answer.push_back(-1);
                continue;
            }
            int size = r - l + 1;
            int targetRank = (size + 1) / 2; // 1-indexed rank for median (works for both parities)

            // binary search on value domain [0, maxPossibleQ] using count_leq
            long long lo = 0, hi = 2000000000LL;
            while (lo < hi) {
                long long mid = lo + (hi - lo) / 2;
                auto res = queryNode(1, 0, n - 1, l, r, mid);
                if (res.first >= targetRank) hi = mid;
                else lo = mid + 1;
            }
            long long median = lo;

            auto res = queryNode(1, 0, n - 1, l, r, median);
            long long countLeq = res.first, sumLeq = res.second;
            auto full = queryNode(1, 0, n - 1, l, r, 2000000000LL);
            long long sumAll = full.second;
            long long countAll = full.first;

            long long sumGreater = sumAll - sumLeq;
            long long countGreater = countAll - countLeq;

            long long cost = (median * countLeq - sumLeq) + (sumGreater - median * countGreater);
            answer.push_back(cost);
        }

        return answer;
    }
};
