// @leetcode id=3760 questionId=4087 slug=maximum-substrings-with-distinct-start lang=cpp site=leetcode.com title="Maximum Substrings With Distinct Start"
class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> seen(s.begin(), s.end());
        return seen.size();
    }
};
