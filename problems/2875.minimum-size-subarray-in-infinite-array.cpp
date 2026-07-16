// @leetcode id=2875 questionId=3141 slug=minimum-size-subarray-in-infinite-array lang=cpp site=leetcode.com title="Minimum Size Subarray in Infinite Array"
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums) total += x;

        long long k = target / total;
        long long remainder = target % total;

        if (remainder == 0) {
            return (int)(k * n);
        }

        vector<int> doubled(nums);
        doubled.insert(doubled.end(), nums.begin(), nums.end());

        long long sum = 0;
        int left = 0;
        int best = INT_MAX;
        for (int right = 0; right < (int)doubled.size(); right++) {
            sum += doubled[right];
            while (sum > remainder) {
                sum -= doubled[left];
                left++;
            }
            if (sum == remainder) {
                best = min(best, right - left + 1);
            }
        }

        if (best == INT_MAX) return -1;
        return (int)(k * n) + best;
    }
};
