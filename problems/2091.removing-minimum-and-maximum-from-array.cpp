// @leetcode id=2091 questionId=2212 slug=removing-minimum-and-maximum-from-array lang=cpp site=leetcode.com title="Removing Minimum and Maximum From Array"
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        int lo = min(minIdx, maxIdx), hi = max(minIdx, maxIdx);
        int bothFront = hi + 1;
        int bothBack = n - lo;
        int mixed = (lo + 1) + (n - hi);
        return min({bothFront, bothBack, mixed});
    }
};
