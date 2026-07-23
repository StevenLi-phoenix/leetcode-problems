// @leetcode id=2824 questionId=2917 slug=count-pairs-whose-sum-is-less-than-target lang=cpp site=leetcode.com title="Count Pairs Whose Sum is Less than Target"
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] < target) count++;
            }
        }
        return count;
    }
};
