// @leetcode id=1673 questionId=1792 slug=find-the-most-competitive-subsequence lang=cpp site=leetcode.com title="Find the Most Competitive Subsequence"
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stk;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.back() > nums[i] && (int)stk.size() + (n - i) > k) {
                stk.pop_back();
            }
            if ((int)stk.size() < k) stk.push_back(nums[i]);
        }
        return stk;
    }
};
