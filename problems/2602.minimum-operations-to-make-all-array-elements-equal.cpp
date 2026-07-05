// @leetcode id=2602 questionId=2718 slug=minimum-operations-to-make-all-array-elements-equal lang=cpp site=leetcode.com title="Minimum Operations to Make All Array Elements Equal"
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + nums[i];

        vector<long long> ans;
        ans.reserve(queries.size());
        for (int q : queries) {
            int idx = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long leftCount = idx, rightCount = n - idx;
            long long leftSum = prefix[idx], rightSum = prefix[n] - prefix[idx];
            long long cost = (long long)q * leftCount - leftSum + rightSum - (long long)q * rightCount;
            ans.push_back(cost);
        }
        return ans;
    }
};
