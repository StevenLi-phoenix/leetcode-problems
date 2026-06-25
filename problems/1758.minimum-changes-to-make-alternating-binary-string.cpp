// @leetcode id=1758 questionId=1884 slug=minimum-changes-to-make-alternating-binary-string lang=cpp site=leetcode.com title="Minimum Changes To Make Alternating Binary String"
class Solution {
    public:
    int minOperations(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    if (s[i] - '0' != i % 2) cnt++;
    return min(cnt, (int)s.size() - cnt);
    }
    };
