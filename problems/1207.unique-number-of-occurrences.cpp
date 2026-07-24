// @leetcode id=1207 questionId=1319 slug=unique-number-of-occurrences lang=cpp site=leetcode.com title="Unique Number of Occurrences"
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int x : arr) count[x]++;

        unordered_set<int> seen;
        for (auto& [_, c] : count) {
            if (!seen.insert(c).second) return false;
        }
        return true;
    }
};
