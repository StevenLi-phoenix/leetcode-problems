// @leetcode id=3978 questionId=4354 slug=unique-middle-element lang=cpp site=leetcode.com title="Unique Middle Element"
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums[nums.size() / 2];
        int count = 0;
        for (int x : nums) {
            if (x == mid) count++;
        }
        return count == 1;
    }
};
