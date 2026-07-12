// @leetcode id=2552 questionId=2682 slug=count-increasing-quadruplets lang=cpp site=leetcode.com title="Count Increasing Quadruplets"
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        // For each pair (j,k), j<k, nums[j]>nums[k], the quadruplet count it
        // contributes is L(j,k)*R(j,k), where L = count of i<j with
        // nums[i]<nums[k], and R = count of l>k with nums[l]>nums[j].
        // A Fenwick tree over values, holding the current suffix (k+1..n-1),
        // answers R(j,k) queries in O(log n); L(j,k) is tracked incrementally
        // while scanning j for a fixed k.
        int n = nums.size();
        vector<int> bit(n + 2, 0);
        auto update = [&](int v, int delta) {
            for (; v <= n; v += v & (-v)) bit[v] += delta;
        };
        auto prefixSum = [&](int v) {
            int res = 0;
            for (; v > 0; v -= v & (-v)) res += bit[v];
            return res;
        };

        int suffixSize = 0;
        for (int i = 1; i < n; i++) { update(nums[i], 1); suffixSize++; }

        long long ans = 0;
        for (int k = 0; k < n; k++) {
            long long cntLess = 0;
            for (int j = 0; j < k; j++) {
                if (nums[j] > nums[k]) {
                    long long greater = suffixSize - prefixSum(nums[j]);
                    ans += cntLess * greater;
                }
                if (nums[j] < nums[k]) cntLess++;
            }
            if (k + 1 < n) { update(nums[k + 1], -1); suffixSize--; }
        }
        return ans;
    }
};
