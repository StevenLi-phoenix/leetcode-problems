// @leetcode id=1608 questionId=1730 slug=special-array-with-x-elements-greater-than-or-equal-x lang=cpp site=leetcode.com title="Special Array With X Elements Greater Than or Equal X"
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for (int x = 0; x <= n; x++) {
            int count = 0;
            for (int v : nums) {
                if (v >= x) count++;
            }
            if (count == x) return x;
        }
        return -1;
    }
};
