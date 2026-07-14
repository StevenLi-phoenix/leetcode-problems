// @leetcode id=1540 questionId=1647 slug=can-convert-string-in-k-moves lang=cpp site=leetcode.com title="Can Convert String in K Moves"
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) return false;
        vector<int> count(26, 0);
        for (size_t i = 0; i < s.size(); i++) {
            int diff = (t[i] - s[i] + 26) % 26;
            if (diff != 0) count[diff]++;
        }

        for (int d = 1; d < 26; d++) {
            if (count[d] == 0) continue;
            long long maxMove = (long long)d + 26LL * (count[d] - 1);
            if (maxMove > k) return false;
        }
        return true;
    }
};
