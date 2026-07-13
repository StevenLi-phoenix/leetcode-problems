// @leetcode id=2606 questionId=2669 slug=find-the-substring-with-maximum-cost lang=cpp site=leetcode.com title="Find the Substring With Maximum Cost"
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int value[26];
        for (int i = 0; i < 26; i++) value[i] = i + 1;
        for (int i = 0; i < (int)chars.size(); i++) value[chars[i] - 'a'] = vals[i];

        int best = 0, cur = 0;
        for (char c : s) {
            cur = max(0, cur) + value[c - 'a'];
            best = max(best, cur);
        }
        return best;
    }
};
