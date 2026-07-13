// @leetcode id=1929 questionId=2058 slug=concatenation-of-array lang=cpp site=leetcode.com title="Concatenation of Array"
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};
