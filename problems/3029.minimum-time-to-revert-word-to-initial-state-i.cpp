// @leetcode id=3029 questionId=3297 slug=minimum-time-to-revert-word-to-initial-state-i lang=cpp site=leetcode.com title="Minimum Time to Revert Word to Initial State I"
class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        for (int t = 1; ; t++) {
            int shift = t * k;
            if (shift >= n) return t;
            if (word.substr(shift) == word.substr(0, n - shift)) return t;
        }
    }
};
