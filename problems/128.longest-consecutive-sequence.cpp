// @leetcode id=128 questionId=128 slug=longest-consecutive-sequence lang=cpp site=leetcode.com title="Longest Consecutive Sequence"
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int best = 0;
        for (int v : set) {
            if (set.count(v - 1)) continue; // not a sequence start
            int len = 1;
            while (set.count(v + len)) len++;
            best = max(best, len);
        }
        return best;
    }
};
