// @leetcode id=820 questionId=839 slug=short-encoding-of-words lang=cpp site=leetcode.com title="Short Encoding of Words"
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        for (const string& w : words)
            for (int i = 1; i < (int)w.size(); i++)
                s.erase(w.substr(i));
        int ans = 0;
        for (const string& w : s) ans += w.size() + 1;
        return ans;
    }
};
