// @leetcode id=2337 questionId=2414 slug=move-pieces-to-obtain-a-string lang=cpp site=leetcode.com title="Move Pieces to Obtain a String"
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        vector<pair<char, int>> s, t;
        for (int i = 0; i < n; i++) {
            if (start[i] != '_') s.push_back({start[i], i});
            if (target[i] != '_') t.push_back({target[i], i});
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
