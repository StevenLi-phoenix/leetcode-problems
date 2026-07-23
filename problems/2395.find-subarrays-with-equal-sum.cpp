// @leetcode id=2395 questionId=2480 slug=find-subarrays-with-equal-sum lang=cpp site=leetcode.com title="Find Subarrays With Equal Sum"
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<long long> seen;
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            long long sum = (long long)nums[i] + nums[i + 1];
            if (!seen.insert(sum).second) return true;
        }
        return false;
    }
};
