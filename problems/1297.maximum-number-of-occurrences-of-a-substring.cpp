// @leetcode id=1297 questionId=1423 slug=maximum-number-of-occurrences-of-a-substring lang=cpp site=leetcode.com title="Maximum Number of Occurrences of a Substring"
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> count;
        int n = s.size();
        for (int i = 0; i + minSize <= n; i++) {
            string sub = s.substr(i, minSize);
            unordered_set<char> unique(sub.begin(), sub.end());
            if ((int)unique.size() <= maxLetters) count[sub]++;
        }

        int best = 0;
        for (auto& [sub, c] : count) best = max(best, c);
        return best;
    }
};
