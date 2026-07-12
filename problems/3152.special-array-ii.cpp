// @leetcode id=3152 questionId=3427 slug=special-array-ii lang=cpp site=leetcode.com title="Special Array II"
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // reach[i] = furthest index j such that nums[i..j] is special.
        vector<int> reach(n);
        reach[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
            reach[i] = (nums[i] % 2 != nums[i + 1] % 2) ? reach[i + 1] : i;

        vector<bool> ans(queries.size());
        for (int q = 0; q < (int)queries.size(); q++)
            ans[q] = reach[queries[q][0]] >= queries[q][1];
        return ans;
    }
};
