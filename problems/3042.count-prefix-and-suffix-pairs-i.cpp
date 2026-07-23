// @leetcode id=3042 questionId=3309 slug=count-prefix-and-suffix-pairs-i lang=cpp site=leetcode.com title="Count Prefix and Suffix Pairs I"
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        auto isPrefixAndSuffix = [](const string& s1, const string& s2) {
            if (s1.size() > s2.size()) return false;
            return s2.compare(0, s1.size(), s1) == 0 &&
                   s2.compare(s2.size() - s1.size(), s1.size(), s1) == 0;
        };

        int count = 0;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) count++;
            }
        }
        return count;
    }
};
