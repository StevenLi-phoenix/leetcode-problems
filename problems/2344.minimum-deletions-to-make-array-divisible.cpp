// @leetcode id=2344 questionId=2423 slug=minimum-deletions-to-make-array-divisible lang=cpp site=leetcode.com title="Minimum Deletions to Make Array Divisible"
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = 0;
        for (int v : numsDivide) g = gcd(g, v);

        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size(); i++) {
            if (g % nums[i] == 0) return i;
        }
        return -1;
    }
};
