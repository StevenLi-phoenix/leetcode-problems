// @leetcode id=2057 questionId=2181 slug=smallest-index-with-equal-value lang=cpp site=leetcode.com title="Smallest Index With Equal Value"
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i % 10 == nums[i]) return i;
        }
        return -1;
    }
};
