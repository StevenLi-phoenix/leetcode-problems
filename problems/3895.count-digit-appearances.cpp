// @leetcode id=3895 questionId=4280 slug=count-digit-appearances lang=cpp site=leetcode.com title="Count Digit Appearances"
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        char d = '0' + digit;
        for (int num : nums) {
            string s = to_string(num);
            for (char c : s) {
                if (c == d) count++;
            }
        }
        return count;
    }
};
