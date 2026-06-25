// @leetcode id=2553 questionId=2639 slug=separate-the-digits-in-an-array lang=cpp site=leetcode.com title="Separate the Digits in an Array"
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for (int num : nums) {
            string s = to_string(num);
            for (char c : s) {
                answer.push_back(c - '0');
            }
        }
        return answer;
    }
};
