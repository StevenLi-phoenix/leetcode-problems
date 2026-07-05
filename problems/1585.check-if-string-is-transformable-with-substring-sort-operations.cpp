// @leetcode id=1585 questionId=1707 slug=check-if-string-is-transformable-with-substring-sort-operations lang=cpp site=leetcode.com title="Check If String Is Transformable With Substring Sort Operations"
class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<queue<int>> pos(10);
        for (int i = 0; i < (int)s.size(); ++i) pos[s[i] - '0'].push(i);

        for (char c : t) {
            int d = c - '0';
            if (pos[d].empty()) return false;
            int p = pos[d].front();
            for (int k = 0; k < d; ++k) {
                if (!pos[k].empty() && pos[k].front() < p) return false;
            }
            pos[d].pop();
        }
        return true;
    }
};
