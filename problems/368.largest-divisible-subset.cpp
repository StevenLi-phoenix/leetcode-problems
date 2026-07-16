// @leetcode id=368 questionId=368 slug=largest-divisible-subset lang=cpp site=leetcode.com title="Largest Divisible Subset"
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), parent(n, -1);
        int best = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((long long)nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[best]) best = i;
        }

        vector<int> result;
        for (int i = best; i != -1; i = parent[i]) {
            result.push_back(nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
