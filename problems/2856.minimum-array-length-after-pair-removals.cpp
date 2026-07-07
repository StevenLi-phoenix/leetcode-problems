// @leetcode id=2856 questionId=3081 slug=minimum-array-length-after-pair-removals lang=cpp site=leetcode.com title="Minimum Array Length After Pair Removals"
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int maxFreq = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && nums[j] == nums[i]) ++j;
            maxFreq = max(maxFreq, j - i);
            i = j;
        }

        if (maxFreq > n - maxFreq) {
            return 2 * maxFreq - n;
        }
        return n % 2;
    }
};
