// @leetcode id=1979 questionId=2106 slug=find-greatest-common-divisor-of-array lang=cpp site=leetcode.com title="Find Greatest Common Divisor of Array"
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        return gcd(mn, mx);
    }
};
