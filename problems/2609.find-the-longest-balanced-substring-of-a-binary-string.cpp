// @leetcode id=2609 questionId=2723 slug=find-the-longest-balanced-substring-of-a-binary-string lang=cpp site=leetcode.com title="Find the Longest Balanced Substring of a Binary String"
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        while (i < n) {
            // Count consecutive zeros
            int zeros = 0;
            while (i < n && s[i] == '0') { zeros++; i++; }
            // Count consecutive ones
            int ones = 0;
            while (i < n && s[i] == '1') { ones++; i++; }
            ans = max(ans, 2 * min(zeros, ones));
        }
        return ans;
    }
};
