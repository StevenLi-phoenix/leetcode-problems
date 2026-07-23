// @leetcode id=3550 questionId=3869 slug=smallest-index-with-digit-sum-equal-to-index lang=cpp site=leetcode.com title="Smallest Index With Digit Sum Equal to Index"
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            int digitSum = 0, x = nums[i];
            do {
                digitSum += x % 10;
                x /= 10;
            } while (x > 0);
            if (digitSum == i) return i;
        }
        return -1;
    }
};
