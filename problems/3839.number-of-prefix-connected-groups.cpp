// @leetcode id=3839 questionId=4137 slug=number-of-prefix-connected-groups lang=cpp site=leetcode.com title="Number of Prefix Connected Groups"
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> prefixCount;
        for (auto& w : words) {
            if ((int)w.size() >= k) {
                ++prefixCount[w.substr(0, k)];
            }
        }

        int groups = 0;
        for (auto& [prefix, cnt] : prefixCount) {
            if (cnt >= 2) ++groups;
        }
        return groups;
    }
};
