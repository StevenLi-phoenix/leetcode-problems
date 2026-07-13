// @leetcode id=2587 questionId=2655 slug=rearrange-array-to-maximize-prefix-score lang=cpp site=leetcode.com title="Rearrange Array to Maximize Prefix Score"
class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum = 0;
        int count = 0;
        for (int v : nums) {
            sum += v;
            if (sum > 0) count++;
            else break;
        }
        return count;
    }
};
