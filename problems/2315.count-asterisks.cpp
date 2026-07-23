// @leetcode id=2315 questionId=2401 slug=count-asterisks lang=cpp site=leetcode.com title="Count Asterisks"
class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        int pipeCount = 0;
        for (char c : s) {
            if (c == '|') pipeCount++;
            else if (c == '*' && pipeCount % 2 == 0) count++;
        }
        return count;
    }
};
