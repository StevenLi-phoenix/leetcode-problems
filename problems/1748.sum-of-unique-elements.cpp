// @leetcode id=1748 questionId=1848 slug=sum-of-unique-elements lang=cpp site=leetcode.com title="Sum of Unique Elements"
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        int sum = 0;
        for (auto& [val, cnt] : freq) {
            if (cnt == 1) sum += val;
        }
        return sum;
    }
};
