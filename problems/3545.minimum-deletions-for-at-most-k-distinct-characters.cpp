// @leetcode id=3545 questionId=3871 slug=minimum-deletions-for-at-most-k-distinct-characters lang=cpp site=leetcode.com title="Minimum Deletions for At Most K Distinct Characters"
class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        vector<int> counts;
        for (int f : freq) if (f > 0) counts.push_back(f);

        sort(counts.begin(), counts.end());
        int distinct = counts.size();
        int deletions = 0;
        int i = 0;
        while (distinct > k) {
            deletions += counts[i++];
            distinct--;
        }
        return deletions;
    }
};
