// @leetcode id=3375 questionId=3621 slug=minimum-operations-to-make-array-values-equal-to-k lang=cpp site=leetcode.com title="Minimum Operations to Make Array Values Equal to K"
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> distinctAboveK;
        for (int v : nums) {
            if (v < k) return -1;
            if (v > k) distinctAboveK.insert(v);
        }
        return (int)distinctAboveK.size();
    }
};
