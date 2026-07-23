// @leetcode id=1431 questionId=1528 slug=kids-with-the-greatest-number-of-candies lang=cpp site=leetcode.com title="Kids With the Greatest Number of Candies"
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> result(candies.size());
        for (int i = 0; i < (int)candies.size(); i++) {
            result[i] = (candies[i] + extraCandies >= maxCandies);
        }
        return result;
    }
};
