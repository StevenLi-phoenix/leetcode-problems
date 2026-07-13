// @leetcode id=2382 questionId=2466 slug=maximum-segment-sum-after-removals lang=cpp site=leetcode.com title="Maximum Segment Sum After Removals"
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        // Process removals in reverse, i.e. "add elements back" one at a
        // time, merging with active neighbors via union-find while tracking
        // the running maximum segment sum.
        int n = nums.size();
        vector<int> parent(n);
        vector<long long> sum(n, 0);
        vector<bool> active(n, false);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a != b) { parent[a] = b; sum[b] += sum[a]; }
        };

        vector<long long> ans(n);
        ans[n - 1] = 0;
        long long globalMax = 0;

        for (int k = n - 1; k >= 1; k--) {
            int idx = removeQueries[k];
            active[idx] = true;
            sum[idx] = nums[idx];
            globalMax = max(globalMax, sum[idx]);

            if (idx - 1 >= 0 && active[idx - 1]) {
                unite(idx - 1, idx);
                globalMax = max(globalMax, sum[find(idx)]);
            }
            if (idx + 1 < n && active[idx + 1]) {
                unite(idx, idx + 1);
                globalMax = max(globalMax, sum[find(idx)]);
            }
            ans[k - 1] = globalMax;
        }
        return ans;
    }
};
