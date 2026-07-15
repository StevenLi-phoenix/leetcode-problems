// @leetcode id=2640 questionId=2676 slug=find-the-score-of-all-prefixes-of-an-array lang=cpp site=leetcode.com title="Find the Score of All Prefixes of an Array"
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n);
        long long runningMax = 0, runningSum = 0;
        for (int i = 0; i < n; i++) {
            runningMax = max(runningMax, (long long)nums[i]);
            runningSum += nums[i] + runningMax;
            result[i] = runningSum;
        }
        return result;
    }
};
