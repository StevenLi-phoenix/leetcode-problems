// @leetcode id=2206 questionId=2308 slug=divide-array-into-equal-pairs lang=cpp site=leetcode.com title="Divide Array Into Equal Pairs"
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int x : nums) count[x]++;
        for (auto& [_, c] : count) {
            if (c % 2 != 0) return false;
        }
        return true;
    }
};
