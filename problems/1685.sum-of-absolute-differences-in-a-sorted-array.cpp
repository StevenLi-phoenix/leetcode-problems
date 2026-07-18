// @leetcode id=1685 questionId=1787 slug=sum-of-absolute-differences-in-a-sorted-array lang=cpp site=leetcode.com title="Sum of Absolute Differences in a Sorted Array"
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            long long leftSum = prefix[i];
            long long rightSum = prefix[n] - prefix[i + 1];
            long long leftContrib = (long long)nums[i] * i - leftSum;
            long long rightContrib = rightSum - (long long)nums[i] * (n - i - 1);
            result[i] = (int)(leftContrib + rightContrib);
        }

        return result;
    }
};
