// @leetcode id=2788 questionId=2881 slug=split-strings-by-separator lang=cpp site=leetcode.com title="Split Strings by Separator"
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for (const string& w : words) {
            string cur;
            for (char c : w) {
                if (c == separator) {
                    if (!cur.empty()) res.push_back(cur);
                    cur.clear();
                } else {
                    cur += c;
                }
            }
            if (!cur.empty()) res.push_back(cur);
        }
        return res;
    }
};
