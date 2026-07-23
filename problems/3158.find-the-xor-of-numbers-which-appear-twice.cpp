// @leetcode id=3158 questionId=3428 slug=find-the-xor-of-numbers-which-appear-twice lang=cpp site=leetcode.com title="Find the XOR of Numbers Which Appear Twice"
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int result = 0;
        for (auto& [val, count] : freq) {
            if (count == 2) result ^= val;
        }
        return result;
    }
};
