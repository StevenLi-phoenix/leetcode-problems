// @leetcode id=2592 questionId=2664 slug=maximize-greatness-of-an-array lang=cpp site=leetcode.com title="Maximize Greatness of an Array"
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] > nums[i]) i++;
        }
        return i;
    }
};
