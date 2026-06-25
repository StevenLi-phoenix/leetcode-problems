// @leetcode id=1189 questionId=1297 slug=maximum-number-of-balloons lang=cpp site=leetcode.com title="Maximum Number of Balloons"
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26] = {};
        for (char c : text) cnt[c - 'a']++;
        // "balloon" needs: b=1, a=1, l=2, o=2, n=1
        return min({cnt['b'-'a'], cnt['a'-'a'], cnt['l'-'a']/2, cnt['o'-'a']/2, cnt['n'-'a']});
    }
};
