// @leetcode id=893 questionId=929 slug=groups-of-special-equivalent-strings lang=cpp site=leetcode.com title="Groups of Special-Equivalent Strings"
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> groups;
        for (const string& w : words) {
            string even, odd;
            for (size_t i = 0; i < w.size(); i++) {
                if (i % 2 == 0) even += w[i];
                else odd += w[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            groups.insert(even + "#" + odd);
        }
        return (int)groups.size();
    }
};
