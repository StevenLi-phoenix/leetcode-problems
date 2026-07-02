// @leetcode id=2568 questionId=2705 slug=minimum-impossible-or lang=cpp site=leetcode.com title="Minimum Impossible OR"
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> present(nums.begin(), nums.end());
        int power = 1;
        while (present.count(power)) power <<= 1;
        return power;
    }
};
