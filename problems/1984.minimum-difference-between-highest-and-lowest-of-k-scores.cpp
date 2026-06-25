// @leetcode id=1984 questionId=2112 slug=minimum-difference-between-highest-and-lowest-of-k-scores lang=cpp site=leetcode.com title="Minimum Difference Between Highest and Lowest of K Scores"
class Solution {
public:
int minimumDifference(vector<int>& nums, int k) {
sort(nums.begin(), nums.end());
int ans = INT_MAX;
for (int i = 0; i+k-1 < (int)nums.size(); i++)
ans = min(ans, nums[i+k-1] - nums[i]);
return ans;
}
};
