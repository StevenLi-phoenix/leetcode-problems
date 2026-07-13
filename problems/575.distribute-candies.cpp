// @leetcode id=575 questionId=575 slug=distribute-candies lang=cpp site=leetcode.com title="Distribute Candies"
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types(candyType.begin(), candyType.end());
        return min(types.size(), candyType.size() / 2);
    }
};
