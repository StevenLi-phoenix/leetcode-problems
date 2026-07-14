// @leetcode id=985 questionId=1027 slug=sum-of-even-numbers-after-queries lang=cpp site=leetcode.com title="Sum of Even Numbers After Queries"
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long evenSum = 0;
        for (int v : nums) if (v % 2 == 0) evenSum += v;

        vector<int> result;
        for (auto& q : queries) {
            int val = q[0], idx = q[1];
            if (nums[idx] % 2 == 0) evenSum -= nums[idx];
            nums[idx] += val;
            if (nums[idx] % 2 == 0) evenSum += nums[idx];
            result.push_back((int)evenSum);
        }
        return result;
    }
};
