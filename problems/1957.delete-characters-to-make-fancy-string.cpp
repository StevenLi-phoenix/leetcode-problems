// @leetcode id=1957 questionId=1302 slug=delete-characters-to-make-fancy-string lang=cpp site=leetcode.com title="Delete Characters to Make Fancy String"
class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        int count = 0;
        char lastChar = '\0';

        for (char c : s) {
            if (c == lastChar) {
                count++;
            } else {
                lastChar = c;
                count = 1;
            }

            if (count <= 2) {
                result += c;
            }
        }

        return result;
    }
};
