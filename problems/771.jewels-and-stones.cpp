// @leetcode id=771 questionId=782 slug=jewels-and-stones lang=cpp site=leetcode.com title="Jewels and Stones"
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        int count = 0;
        for (char c : stones) {
            if (jewelSet.count(c)) ++count;
        }
        return count;
    }
};
