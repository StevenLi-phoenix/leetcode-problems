// @leetcode id=2255 questionId=2341 slug=count-prefixes-of-a-given-string lang=cpp site=leetcode.com title="Count Prefixes of a Given String"
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (const string& w : words) {
            if (w.size() <= s.size() && s.compare(0, w.size(), w) == 0) count++;
        }
        return count;
    }
};
