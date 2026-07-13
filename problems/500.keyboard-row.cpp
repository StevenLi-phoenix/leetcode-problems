// @leetcode id=500 questionId=500 slug=keyboard-row lang=cpp site=leetcode.com title="Keyboard Row"
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int row[26];
        for (char c : string("qwertyuiop")) row[c - 'a'] = 0;
        for (char c : string("asdfghjkl")) row[c - 'a'] = 1;
        for (char c : string("zxcvbnm")) row[c - 'a'] = 2;

        vector<string> ans;
        for (auto& w : words) {
            int r = row[tolower(w[0]) - 'a'];
            bool ok = true;
            for (char c : w)
                if (row[tolower(c) - 'a'] != r) { ok = false; break; }
            if (ok) ans.push_back(w);
        }
        return ans;
    }
};
