// @leetcode id=1283 questionId=1408 slug=find-the-smallest-divisor-given-a-threshold lang=cpp site=leetcode.com title="Find the Smallest Divisor Given a Threshold"
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        
        auto getSum = [&](int d) {
            long long sum = 0;
            for (int x : nums) {
                sum += (x + d - 1) / d;
            }
            return sum;
        };
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (getSum(mid) <= threshold) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};
