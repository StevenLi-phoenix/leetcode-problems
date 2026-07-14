// @leetcode id=2971 questionId=3262 slug=find-polygon-with-the-largest-perimeter lang=cpp site=leetcode.com title="Find Polygon With the Largest Perimeter"
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        long long best = -1;
        for (int i = n - 1; i >= 2; i--) {
            long long sumOthers = prefix[i];
            if (sumOthers > nums[i]) {
                best = sumOthers + nums[i];
                break;
            }
        }
        return best;
    }
};
