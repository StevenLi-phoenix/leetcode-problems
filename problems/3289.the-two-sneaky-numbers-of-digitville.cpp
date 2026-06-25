// @leetcode id=3289 questionId=3581 slug=the-two-sneaky-numbers-of-digitville lang=cpp site=leetcode.com title="The Two Sneaky Numbers of Digitville"
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> cnt;
        vector<int> result;
        for (int x : nums) {
            cnt[x]++;
            if (cnt[x] == 2) result.push_back(x);
        }
        return result;
    }
};
