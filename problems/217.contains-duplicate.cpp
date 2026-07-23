// @leetcode id=217 questionId=217 slug=contains-duplicate lang=cpp site=leetcode.com title="Contains Duplicate"
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (!seen.insert(x).second) return true;
        }
        return false;
    }
};
