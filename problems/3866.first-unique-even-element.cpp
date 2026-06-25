// @leetcode id=3866 questionId=4252 slug=first-unique-even-element lang=cpp site=leetcode.com title="First Unique Even Element"
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            if (x % 2 == 0) freq[x]++;
        }
        for (int x : nums) {
            if (x % 2 == 0 && freq[x] == 1) return x;
        }
        return -1;
    }
};
