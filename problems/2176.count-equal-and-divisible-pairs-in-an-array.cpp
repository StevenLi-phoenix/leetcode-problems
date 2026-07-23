// @leetcode id=2176 questionId=2277 slug=count-equal-and-divisible-pairs-in-an-array lang=cpp site=leetcode.com title="Count Equal and Divisible Pairs in an Array"
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (long long)i * j % k == 0) count++;
            }
        }
        return count;
    }
};
