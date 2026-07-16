// @leetcode id=532 questionId=532 slug=k-diff-pairs-in-an-array lang=cpp site=leetcode.com title="K-diff Pairs in an Array"
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int x : nums) count[x]++;

        int result = 0;
        if (k == 0) {
            for (auto& [val, cnt] : count) {
                if (cnt >= 2) result++;
            }
        } else {
            for (auto& [val, cnt] : count) {
                if (count.count(val + k)) result++;
            }
        }
        return result;
    }
};
