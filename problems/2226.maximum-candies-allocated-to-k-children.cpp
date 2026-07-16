// @leetcode id=2226 questionId=1335 slug=maximum-candies-allocated-to-k-children lang=cpp site=leetcode.com title="Maximum Candies Allocated to K Children"
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long lo = 1, hi = 0;
        for (int c : candies) hi = max(hi, (long long)c);
        int result = 0;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count = 0;
            for (int c : candies) count += c / mid;
            if (count >= k) {
                result = (int)mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return result;
    }
};
