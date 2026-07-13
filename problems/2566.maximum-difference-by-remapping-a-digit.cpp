// @leetcode id=2566 questionId=2704 slug=maximum-difference-by-remapping-a-digit lang=cpp site=leetcode.com title="Maximum Difference by Remapping a Digit"
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        string maxS = s;
        char firstNonNine = 0;
        for (char c : s) {
            if (c != '9') {
                firstNonNine = c;
                break;
            }
        }
        if (firstNonNine != 0) {
            for (char& c : maxS) if (c == firstNonNine) c = '9';
        }

        string minS = s;
        char firstDigit = s[0];
        for (char& c : minS) if (c == firstDigit) c = '0';

        return stoi(maxS) - stoi(minS);
    }
};
