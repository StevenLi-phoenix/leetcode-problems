// @leetcode id=2465 questionId=2561 slug=number-of-distinct-averages lang=cpp site=leetcode.com title="Number of Distinct Averages"
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_set<double> averages;
        for (int i = 0; i < n / 2; i++) {
            averages.insert((nums[i] + nums[n - 1 - i]) / 2.0);
        }
        return averages.size();
    }
};
