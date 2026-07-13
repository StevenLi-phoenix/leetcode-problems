// @leetcode id=1647 questionId=1770 slug=minimum-deletions-to-make-character-frequencies-unique lang=cpp site=leetcode.com title="Minimum Deletions to Make Character Frequencies Unique"
class Solution {
public:
    int minDeletions(string s) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;

        vector<int> freqs;
        for (int c : count) if (c > 0) freqs.push_back(c);
        sort(freqs.begin(), freqs.end(), greater<int>());

        int deletions = 0;
        unordered_set<int> used;
        for (int f : freqs) {
            while (f > 0 && used.count(f)) {
                f--;
                deletions++;
            }
            if (f > 0) used.insert(f);
        }
        return deletions;
    }
};
