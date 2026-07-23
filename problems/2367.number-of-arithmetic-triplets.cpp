// @leetcode id=2367 questionId=2442 slug=number-of-arithmetic-triplets lang=cpp site=leetcode.com title="Number of Arithmetic Triplets"
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> present(nums.begin(), nums.end());
        int count = 0;
        for (int x : nums) {
            if (present.count(x + diff) && present.count(x + 2 * diff)) count++;
        }
        return count;
    }
};
