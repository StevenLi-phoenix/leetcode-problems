// @leetcode id=809 questionId=827 slug=expressive-words lang=cpp site=leetcode.com title="Expressive Words"
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> sGroups = getGroups(s);
        int count = 0;
        for (auto& w : words) {
            if (isStretchy(sGroups, getGroups(w))) count++;
        }
        return count;
    }

private:
    vector<pair<char, int>> getGroups(const string& s) {
        vector<pair<char, int>> groups;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            groups.push_back({s[i], j - i});
            i = j;
        }
        return groups;
    }

    bool isStretchy(vector<pair<char, int>>& sGroups, vector<pair<char, int>> wGroups) {
        if (sGroups.size() != wGroups.size()) return false;
        for (size_t i = 0; i < sGroups.size(); i++) {
            if (sGroups[i].first != wGroups[i].first) return false;
            int sc = sGroups[i].second, wc = wGroups[i].second;
            if (sc == wc) continue;
            if (sc < wc) return false;
            if (sc < 3) return false;
        }
        return true;
    }
};
