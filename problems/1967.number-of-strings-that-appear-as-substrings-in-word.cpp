// @leetcode id=1967 questionId=2099 slug=number-of-strings-that-appear-as-substrings-in-word lang=cpp site=leetcode.com title="Number of Strings That Appear as Substrings in Word"
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }
        return count;
    }
};
