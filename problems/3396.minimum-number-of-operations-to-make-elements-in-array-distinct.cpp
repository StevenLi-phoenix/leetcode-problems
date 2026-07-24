// @leetcode id=3396 questionId=3656 slug=minimum-number-of-operations-to-make-elements-in-array-distinct lang=cpp site=leetcode.com title="Minimum Number of Operations to Make Elements in Array Distinct"
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int ops = 0;
        while (true) {
            unordered_set<int> seen;
            bool distinct = true;
            for (int i = start; i < n; i++) {
                if (!seen.insert(nums[i]).second) { distinct = false; break; }
            }
            if (distinct) return ops;
            start += 3;
            ops++;
        }
    }
};
