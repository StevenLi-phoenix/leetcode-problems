// @leetcode id=1624 questionId=1746 slug=largest-substring-between-two-equal-characters lang=cpp site=leetcode.com title="Largest Substring Between Two Equal Characters"
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int first[26];
        fill(first, first + 26, -1);
        int ans = -1;
        for (int i = 0; i < (int)s.size(); ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            else ans = max(ans, i - first[c] - 1);
        }
        return ans;
    }
};
