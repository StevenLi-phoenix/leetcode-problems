// @leetcode id=2390 questionId=2470 slug=removing-stars-from-a-string lang=cpp site=leetcode.com title="Removing Stars From a String"
class Solution {
public:
    string removeStars(string s) {
        string result;
        for (char c : s) {
            if (c == '*') result.pop_back();
            else result.push_back(c);
        }
        return result;
    }
};
