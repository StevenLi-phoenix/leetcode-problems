// @leetcode id=1664 questionId=1783 slug=ways-to-make-a-fair-array lang=cpp site=leetcode.com title="Ways to Make a Fair Array"
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        long long totalEven = 0, totalOdd = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) totalEven += nums[i];
            else totalOdd += nums[i];
        }

        long long prefixEven = 0, prefixOdd = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long suffixEven = totalEven - prefixEven - (i % 2 == 0 ? nums[i] : 0);
            long long suffixOdd = totalOdd - prefixOdd - (i % 2 == 1 ? nums[i] : 0);

            long long newEven = prefixEven + suffixOdd;
            long long newOdd = prefixOdd + suffixEven;

            if (newEven == newOdd) count++;

            if (i % 2 == 0) prefixEven += nums[i];
            else prefixOdd += nums[i];
        }
        return count;
    }
};
