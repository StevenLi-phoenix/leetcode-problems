// @leetcode id=1991 questionId=2102 slug=find-the-middle-index-in-array lang=cpp site=leetcode.com title="Find the Middle Index in Array"
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) totalSum += x;
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
