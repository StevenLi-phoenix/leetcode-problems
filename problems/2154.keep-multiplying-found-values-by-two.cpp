// @leetcode id=2154 questionId=2274 slug=keep-multiplying-found-values-by-two lang=cpp site=leetcode.com title="Keep Multiplying Found Values by Two"
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(original)) {
            original *= 2;
        }
        return original;
    }
};
