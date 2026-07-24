// @leetcode id=414 questionId=414 slug=third-maximum-number lang=cpp site=leetcode.com title="Third Maximum Number"
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int>> distinct(nums.begin(), nums.end());
        auto it = distinct.begin();
        if (distinct.size() < 3) return *it;
        advance(it, 2);
        return *it;
    }
};
