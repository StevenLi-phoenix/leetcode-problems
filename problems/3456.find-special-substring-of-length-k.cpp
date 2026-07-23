// @leetcode id=3456 questionId=3709 slug=find-special-substring-of-length-k lang=cpp site=leetcode.com title="Find Special Substring of Length K"
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            if (j - i == k) return true;
            i = j;
        }
        return false;
    }
};
