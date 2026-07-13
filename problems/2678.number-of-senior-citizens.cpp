// @leetcode id=2678 questionId=2727 slug=number-of-senior-citizens lang=cpp site=leetcode.com title="Number of Senior Citizens"
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (auto& s : details) {
            int age = (s[11] - '0') * 10 + (s[12] - '0');
            if (age > 60) count++;
        }
        return count;
    }
};
