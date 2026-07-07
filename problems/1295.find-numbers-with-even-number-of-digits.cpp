// @leetcode id=1295 questionId=1421 slug=find-numbers-with-even-number-of-digits lang=cpp site=leetcode.com title="Find Numbers with Even Number of Digits"
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int v : nums) {
            int digits = to_string(v).size();
            if (digits % 2 == 0) ++count;
        }
        return count;
    }
};
