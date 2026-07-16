// @leetcode id=3843 questionId=4217 slug=first-element-with-unique-frequency lang=cpp site=leetcode.com title="First Element with Unique Frequency"
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int x : nums) count[x]++;

        unordered_map<int, int> freqCount;
        for (auto& [val, cnt] : count) freqCount[cnt]++;

        for (int x : nums) {
            if (freqCount[count[x]] == 1) return x;
        }
        return -1;
    }
};
