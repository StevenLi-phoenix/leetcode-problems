// @leetcode id=890 questionId=926 slug=find-and-replace-pattern lang=cpp site=leetcode.com title="Find and Replace Pattern"
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for (auto& w : words) {
            if (matches(w, pattern)) result.push_back(w);
        }
        return result;
    }

private:
    bool matches(const string& w, const string& p) {
        unordered_map<char, char> w2p, p2w;
        for (size_t i = 0; i < w.size(); i++) {
            char a = w[i], b = p[i];
            if (w2p.count(a) && w2p[a] != b) return false;
            if (p2w.count(b) && p2w[b] != a) return false;
            w2p[a] = b;
            p2w[b] = a;
        }
        return true;
    }
};
