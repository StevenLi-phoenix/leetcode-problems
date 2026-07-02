// @leetcode id=2562 questionId=2698 slug=find-the-array-concatenation-value lang=cpp site=leetcode.com title="Find the Array Concatenation Value"
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int lo = 0, hi = (int)nums.size() - 1;
        while (lo < hi) {
            ans += stoll(to_string(nums[lo]) + to_string(nums[hi]));
            ++lo;
            --hi;
        }
        if (lo == hi) ans += nums[lo];
        return ans;
    }
};
