// @leetcode id=2389 questionId=2469 slug=longest-subsequence-with-limited-sum lang=cpp site=leetcode.com title="Longest Subsequence With Limited Sum"
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < (int)nums.size(); i++) nums[i] += nums[i - 1];

        vector<int> ans(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            int idx = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            ans[i] = idx;
        }
        return ans;
    }
};
