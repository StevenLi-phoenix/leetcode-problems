// @leetcode id=2845 questionId=2915 slug=count-of-interesting-subarrays lang=cpp site=leetcode.com title="Count of Interesting Subarrays"
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> freq;
        freq[0] = 1;
        long long result = 0;
        int prefix = 0;
        for (int x : nums) {
            if (x % modulo == k) prefix = (prefix + 1) % modulo;
            int need = (prefix - k % modulo + modulo) % modulo;
            auto it = freq.find(need);
            if (it != freq.end()) result += it->second;
            freq[prefix]++;
        }
        return result;
    }
};
