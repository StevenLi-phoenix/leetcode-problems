// @leetcode id=3137 questionId=3384 slug=minimum-number-of-operations-to-make-word-k-periodic lang=cpp site=leetcode.com title="Minimum Number of Operations to Make Word K-Periodic"
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        int numBlocks = n / k;
        unordered_map<string, int> freq;
        int maxFreq = 0;
        for (int i = 0; i < n; i += k) {
            string block = word.substr(i, k);
            freq[block]++;
            maxFreq = max(maxFreq, freq[block]);
        }
        return numBlocks - maxFreq;
    }
};
