// @leetcode id=3420 questionId=3674 slug=count-non-decreasing-subarrays-after-k-operations lang=cpp site=leetcode.com title="Count Non-Decreasing Subarrays After K Operations"
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> tree1(n + 2, 0), tree2(n + 2, 0);
        auto add = [&](vector<long long>& t, int i, long long delta) {
            for (; i <= n; i += i & (-i)) t[i] += delta;
        };
        auto rangeAdd = [&](vector<long long>& t, int l, int r, long long delta) {
            add(t, l, delta);
            add(t, r + 1, -delta);
        };
        auto pointQuery = [&](vector<long long>& t, int i) -> long long {
            long long s = 0;
            for (; i > 0; i -= i & (-i)) s += t[i];
            return s;
        };

        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) prefixSum[i + 1] = prefixSum[i] + nums[i];

        // monotonic stack of (start, end, value), 0-indexed positions
        vector<array<long long, 3>> stk;

        long long answer = 0;
        int left = 0;

        for (int r = 0; r < n; r++) {
            long long mergedStart = r;
            while (!stk.empty() && stk.back()[2] <= nums[r]) {
                long long a = stk.back()[0], b = stk.back()[1], V = stk.back()[2];
                stk.pop_back();
                rangeAdd(tree1, (int)a + 1, (int)b + 1, -V);
                rangeAdd(tree2, (int)a + 1, (int)b + 1, V * (r - 1));
                mergedStart = min(mergedStart, a);
            }
            stk.push_back({mergedStart, (long long)r, (long long)nums[r]});
            rangeAdd(tree1, (int)mergedStart + 1, r + 1, nums[r]);
            rangeAdd(tree2, (int)mergedStart + 1, r + 1, (long long)nums[r] * (1 - r));

            while (left <= r) {
                long long sumM = pointQuery(tree1, left + 1) * r + pointQuery(tree2, left + 1);
                long long numsSum = prefixSum[r + 1] - prefixSum[left];
                long long cost = sumM - numsSum;
                if (cost <= k) break;
                left++;
            }
            answer += (r - left + 1);
        }

        return answer;
    }
};
