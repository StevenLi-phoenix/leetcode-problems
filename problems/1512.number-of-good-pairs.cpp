// @leetcode id=1512 questionId=1635 slug=number-of-good-pairs lang=cpp site=leetcode.com title="Number of Good Pairs"
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        int result = 0;
        for (int num : nums) {
            result += count[num];
            count[num]++;
        }
        return result;
    }
};
