// @leetcode id=2357 questionId=2436 slug=make-array-zero-by-subtracting-equal-amounts lang=cpp site=leetcode.com title="Make Array Zero by Subtracting Equal Amounts"
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums) {
            if (x > 0) s.insert(x);
        }
        return s.size();
    }
};
