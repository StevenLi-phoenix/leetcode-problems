// @leetcode id=2800 questionId=2877 slug=shortest-string-that-contains-three-strings lang=cpp site=leetcode.com title="Shortest String That Contains Three Strings"
class Solution {
public:
    string merge(const string& x, const string& y) {
        if (x.find(y) != string::npos) return x;
        if (y.find(x) != string::npos) return y;

        for (int len = min(x.size(), y.size()); len > 0; len--) {
            if (x.compare(x.size() - len, len, y, 0, len) == 0) {
                return x + y.substr(len);
            }
        }
        return x + y;
    }

    string minimumString(string a, string b, string c) {
        vector<string> strs = {a, b, c};
        vector<int> idx = {0, 1, 2};
        string best = "";

        sort(idx.begin(), idx.end());
        do {
            string merged = merge(merge(strs[idx[0]], strs[idx[1]]), strs[idx[2]]);
            if (best.empty() || merged.size() < best.size() ||
                (merged.size() == best.size() && merged < best)) {
                best = merged;
            }
        } while (next_permutation(idx.begin(), idx.end()));

        return best;
    }
};
