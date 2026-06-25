// @leetcode id=2974 questionId=3226 slug=minimum-number-game lang=cpp site=leetcode.com title="Minimum Number Game"
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> result;
        for (int i = 0; i < nums.size(); i += 2) {
            result.push_back(nums[i + 1]);
            result.push_back(nums[i]);
        }

        return result;
    }
};
