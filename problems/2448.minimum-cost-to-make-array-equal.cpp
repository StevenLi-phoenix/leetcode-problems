// @leetcode id=2448 questionId=2538 slug=minimum-cost-to-make-array-equal lang=cpp site=leetcode.com title="Minimum Cost to Make Array Equal"
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] < nums[b]; });

        long long totalCost = 0;
        for (int c : cost) totalCost += c;

        long long half = (totalCost + 1) / 2;
        long long acc = 0;
        int target = nums[idx[0]];
        for (int i : idx) {
            acc += cost[i];
            if (acc >= half) {
                target = nums[i];
                break;
            }
        }

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total += (long long)abs(nums[i] - target) * cost[i];
        }
        return total;
    }
};
