// @leetcode id=1910 questionId=2021 slug=remove-all-occurrences-of-a-substring lang=cpp site=leetcode.com title="Remove All Occurrences of a Substring"
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        int plen = part.size();
        for (char c : s) {
            result.push_back(c);
            if ((int)result.size() >= plen &&
                result.compare(result.size() - plen, plen, part) == 0) {
                result.erase(result.size() - plen);
            }
        }
        return result;
    }
};
