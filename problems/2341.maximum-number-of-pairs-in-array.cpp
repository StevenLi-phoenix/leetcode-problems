// @leetcode id=2341 questionId=2421 slug=maximum-number-of-pairs-in-array lang=cpp site=leetcode.com title="Maximum Number of Pairs in Array"
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int v : nums) count[v]++;

        int pairs = 0, leftover = 0;
        for (auto& [v, c] : count) {
            pairs += c / 2;
            leftover += c % 2;
        }
        return {pairs, leftover};
    }
};
