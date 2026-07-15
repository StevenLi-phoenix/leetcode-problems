// @leetcode id=1567 questionId=1690 slug=maximum-length-of-subarray-with-positive-product lang=cpp site=leetcode.com title="Maximum Length of Subarray With Positive Product"
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0, best = 0;
        for (int x : nums) {
            if (x == 0) {
                pos = 0;
                neg = 0;
            } else if (x > 0) {
                pos++;
                neg = neg > 0 ? neg + 1 : 0;
            } else {
                int newPos = neg > 0 ? neg + 1 : 0;
                int newNeg = pos + 1;
                pos = newPos;
                neg = newNeg;
            }
            best = max(best, pos);
        }
        return best;
    }
};
