// @leetcode id=2913 questionId=3163 slug=subarrays-distinct-element-sum-of-squares-i lang=cpp site=leetcode.com title="Subarrays Distinct Element Sum of Squares I"
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                seen.insert(nums[j]);
                long long d = seen.size();
                total += d * d;
            }
        }
        return (int)total;
    }
};
