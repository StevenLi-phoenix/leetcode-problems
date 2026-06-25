// @leetcode id=2744 questionId=2847 slug=find-maximum-number-of-string-pairs lang=cpp site=leetcode.com title="Find Maximum Number of String Pairs"
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> seen;
        int pairs = 0;
        for (const string& w : words) {
            string rev(w.rbegin(), w.rend());
            if (seen.count(rev)) {
                pairs++;
                seen.erase(rev); // each string can be in at most one pair
            } else {
                seen.insert(w);
            }
        }
        return pairs;
    }
};
