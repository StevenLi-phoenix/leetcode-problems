// @leetcode id=3324 questionId=3566 slug=find-the-sequence-of-strings-appeared-on-the-screen lang=cpp site=leetcode.com title="Find the Sequence of Strings Appeared on the Screen"
class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string cur;
        for (char target_c : target) {
            cur += 'a';
            for (char c = 'a'; c <= target_c; c++) {
                cur.back() = c;
                result.push_back(cur);
            }
        }
        return result;
    }
};
