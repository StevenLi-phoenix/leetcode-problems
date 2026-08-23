// @leetcode id=1358 questionId=1460 slug=number-of-substrings-containing-all-three-characters lang=cpp site=leetcode.com title="Number of Substrings Containing All Three Characters"
class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1};
        int result = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            last[s[i] - 'a'] = i;
            if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
                result += 1 + min({last[0], last[1], last[2]});
            }
        }
        return result;
    }
};
