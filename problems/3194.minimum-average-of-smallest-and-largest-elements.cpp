// @leetcode id=3194 questionId=3471 slug=minimum-average-of-smallest-and-largest-elements lang=cpp site=leetcode.com title="Minimum Average of Smallest and Largest Elements"
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;
        double minAverage = DBL_MAX;

        while (left < right) {
            double avg = (nums[left] + nums[right]) / 2.0;
            minAverage = min(minAverage, avg);
            left++;
            right--;
        }

        return minAverage;
    }
};
