// @leetcode id=6 questionId=6 slug=zigzag-conversion lang=cpp site=leetcode.com title="Zigzag Conversion"
class Solution {
public:
    string convert(string s, int numRows) {
        int n = (int)s.size();
        if (numRows <= 1 || numRows >= n) return s;

        vector<string> rows(numRows);
        int r = 0;
        int dir = 1; // +1 going down, -1 going up

        for (char c : s) {
            rows[r].push_back(c);
            if (r == 0) dir = 1;
            else if (r == numRows - 1) dir = -1;
            r += dir;
        }

        string ans;
        ans.reserve(n);
        for (auto &row : rows) ans += row;
        return ans;
    }
};
