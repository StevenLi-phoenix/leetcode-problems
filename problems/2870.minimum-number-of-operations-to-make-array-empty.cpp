// @leetcode id=2870 questionId=3094 slug=minimum-number-of-operations-to-make-array-empty lang=cpp site=leetcode.com title="Minimum Number of Operations to Make Array Empty"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        long long ops = 0;
        for (auto& [val, cnt] : freq) {
            if (cnt == 1) return -1;
            ops += (cnt + 2) / 3;
        }
        return (int)ops;
    }
};
