// @leetcode id=560 questionId=560 slug=subarray-sum-equals-k lang=cpp site=leetcode.com title="Subarray Sum Equals K"
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            auto it = prefixCount.find(sum - k);
            if (it != prefixCount.end()) count += it->second;
            prefixCount[sum]++;
        }
        return count;
    }
};
