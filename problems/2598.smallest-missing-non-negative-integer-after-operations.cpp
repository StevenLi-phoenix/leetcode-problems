// @leetcode id=2598 questionId=2661 slug=smallest-missing-non-negative-integer-after-operations lang=cpp site=leetcode.com title="Smallest Missing Non-negative Integer After Operations"
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> count(value, 0);
        for (int x : nums) {
            int r = ((x % value) + value) % value;
            ++count[r];
        }

        for (int target = 0; ; ++target) {
            int r = target % value;
            if (count[r] > 0) --count[r];
            else return target;
        }
    }
};
