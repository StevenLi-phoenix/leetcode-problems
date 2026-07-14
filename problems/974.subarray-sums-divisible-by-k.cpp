// @leetcode id=974 questionId=1016 slug=subarray-sums-divisible-by-k lang=cpp site=leetcode.com title="Subarray Sums Divisible by K"
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k, 0);
        count[0] = 1;
        int sum = 0, result = 0;
        for (int v : nums) {
            sum = ((sum + v) % k + k) % k;
            result += count[sum];
            count[sum]++;
        }
        return result;
    }
};
