// @leetcode id=3674 questionId=3998 slug=minimum-operations-to-equalize-array lang=cpp site=leetcode.com title="Minimum Operations to Equalize Array"
class Solution {
    public:
        int minOperations(vector<int>& nums) {
                for (int i = 1; i < (int)nums.size(); i++) {
                            if (nums[i] != nums[0]) return 1;
                                    }
                                            return 0;
                                                }
                                                };
