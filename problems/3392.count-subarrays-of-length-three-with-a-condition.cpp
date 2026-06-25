// @leetcode id=3392 questionId=3685 slug=count-subarrays-of-length-three-with-a-condition lang=cpp site=leetcode.com title="Count Subarrays of Length Three With a Condition"
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i + 2 < nums.size(); i++) {
            if ((nums[i] + nums[i+2]) * 2 == nums[i+1]) {
                count++;
            }
        }
        return count;
    }
};
