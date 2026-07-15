// @leetcode id=930 questionId=966 slug=binary-subarrays-with-sum lang=cpp site=leetcode.com title="Binary Subarrays With Sum"
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int prefix = 0, count = 0;
        for (int x : nums) {
            prefix += x;
            auto it = freq.find(prefix - goal);
            if (it != freq.end()) count += it->second;
            freq[prefix]++;
        }
        return count;
    }
};
