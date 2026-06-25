// @leetcode id=3075 questionId=3351 slug=maximize-happiness-of-selected-children lang=cpp site=leetcode.com title="Maximize Happiness of Selected Children"
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long gain = (long long)happiness[i] - i;
            if (gain <= 0) break;          // remaining will be even smaller
            ans += gain;
        }
        return ans;
    }
};
