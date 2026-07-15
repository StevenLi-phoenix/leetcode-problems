// @leetcode id=1433 questionId=1530 slug=check-if-a-string-can-break-another-string lang=cpp site=leetcode.com title="Check If a String Can Break Another String"
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        bool s1BreaksS2 = true, s2BreaksS1 = true;
        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] < s2[i]) s1BreaksS2 = false;
            if (s2[i] < s1[i]) s2BreaksS1 = false;
        }
        return s1BreaksS2 || s2BreaksS1;
    }
};
