// @leetcode id=3076 questionId=3356 slug=shortest-uncommon-substring-in-an-array lang=cpp site=leetcode.com title="Shortest Uncommon Substring in an Array"
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<unordered_set<string>> subsSets(n);
        for (int i = 0; i < n; i++) {
            string& s = arr[i];
            for (int len = 1; len <= (int)s.size(); len++) {
                for (int start = 0; start + len <= (int)s.size(); start++) {
                    subsSets[i].insert(s.substr(start, len));
                }
            }
        }

        vector<string> result(n, "");
        for (int i = 0; i < n; i++) {
            string best = "";
            for (const string& sub : subsSets[i]) {
                bool unique = true;
                for (int j = 0; j < n && unique; j++) {
                    if (j == i) continue;
                    if (subsSets[j].count(sub)) unique = false;
                }
                if (unique) {
                    if (best.empty() || sub.size() < best.size() ||
                        (sub.size() == best.size() && sub < best)) {
                        best = sub;
                    }
                }
            }
            result[i] = best;
        }
        return result;
    }
};
