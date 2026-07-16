// @leetcode id=777 questionId=793 slug=swap-adjacent-in-lr-string lang=cpp site=leetcode.com title="Swap Adjacent in LR String"
class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size();
        vector<pair<char, int>> s, t;
        for (int i = 0; i < n; i++) {
            if (start[i] != 'X') s.push_back({start[i], i});
            if (result[i] != 'X') t.push_back({result[i], i});
        }
        if (s.size() != t.size()) return false;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i].first != t[i].first) return false;
            if (s[i].first == 'L' && s[i].second < t[i].second) return false;
            if (s[i].first == 'R' && s[i].second > t[i].second) return false;
        }
        return true;
    }
};
