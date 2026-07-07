// @leetcode id=686 questionId=686 slug=repeated-string-match lang=cpp site=leetcode.com title="Repeated String Match"
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int base = (b.size() + a.size() - 1) / a.size();

        string repeated;
        repeated.reserve((base + 1) * a.size());
        for (int i = 0; i < base; ++i) repeated += a;

        if (repeated.find(b) != string::npos) return base;
        repeated += a;
        if (repeated.find(b) != string::npos) return base + 1;
        return -1;
    }
};
