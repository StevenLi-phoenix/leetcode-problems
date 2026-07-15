// @leetcode id=2109 questionId=2232 slug=adding-spaces-to-a-string lang=cpp site=leetcode.com title="Adding Spaces to a String"
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        result.reserve(s.size() + spaces.size());
        size_t spaceIdx = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (spaceIdx < spaces.size() && (size_t)spaces[spaceIdx] == i) {
                result += ' ';
                spaceIdx++;
            }
            result += s[i];
        }
        return result;
    }
};
