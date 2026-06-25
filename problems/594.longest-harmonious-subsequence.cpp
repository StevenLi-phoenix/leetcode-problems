// @leetcode id=594 questionId=594 slug=longest-harmonious-subsequence lang=cpp site=leetcode.com title="Longest Harmonious Subsequence"
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        int result = 0;
        for (auto& [val, cnt] : freq) {
            if (freq.count(val + 1)) {
                result = max(result, cnt + freq[val + 1]);
            }
        }
        return result;
    }
};
