// @leetcode id=792 questionId=808 slug=number-of-matching-subsequences lang=cpp site=leetcode.com title="Number of Matching Subsequences"
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int, int>>> buckets(26); // (wordIdx, charIdx) waiting on this letter

        for (int i = 0; i < (int)words.size(); i++) {
            buckets[words[i][0] - 'a'].push_back({i, 0});
        }

        int count = 0;
        for (char c : s) {
            int idx = c - 'a';
            vector<pair<int, int>> waiting = std::move(buckets[idx]);
            buckets[idx].clear();
            for (auto& [wordIdx, charIdx] : waiting) {
                charIdx++;
                if (charIdx == (int)words[wordIdx].size()) {
                    count++;
                } else {
                    buckets[words[wordIdx][charIdx] - 'a'].push_back({wordIdx, charIdx});
                }
            }
        }
        return count;
    }
};
