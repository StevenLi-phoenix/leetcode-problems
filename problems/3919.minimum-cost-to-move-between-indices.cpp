// @leetcode id=3919 questionId=4291 slug=minimum-cost-to-move-between-indices lang=cpp site=leetcode.com title="Minimum Cost to Move Between Indices"
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> gap(n - 1);
        for (int i = 0; i + 1 < n; i++) gap[i] = nums[i + 1] - nums[i];

        const long long INF = LLONG_MAX;
        vector<long long> prefF(n, 0), prefB(n, 0);
        for (int i = 0; i < n - 1; i++) {
            long long leftGap = (i > 0) ? gap[i - 1] : INF;
            long long rightGapForBackward = (i + 1 < n - 1) ? gap[i + 1] : INF;

            bool forwardDiscount = gap[i] < leftGap;
            bool backwardDiscount = gap[i] <= rightGapForBackward;

            long long costForward = forwardDiscount ? 1 : gap[i];
            long long costBackward = backwardDiscount ? 1 : gap[i];

            prefF[i + 1] = prefF[i] + costForward;
            prefB[i + 1] = prefB[i] + costBackward;
        }

        vector<int> result;
        result.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long cost = 0;
            if (l < r) cost = prefF[r] - prefF[l];
            else if (l > r) cost = prefB[l] - prefB[r];
            result.push_back((int)cost);
        }
        return result;
    }
};
