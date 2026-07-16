// @leetcode id=3694 questionId=4021 slug=distinct-points-reachable-after-substring-removal lang=cpp site=leetcode.com title="Distinct Points Reachable After Substring Removal"
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        int dx = 0, dy = 0;
        auto delta = [](char c, int& dx, int& dy) {
            if (c == 'U') dy++;
            else if (c == 'D') dy--;
            else if (c == 'L') dx--;
            else if (c == 'R') dx++;
        };

        for (int i = 0; i < k; i++) delta(s[i], dx, dy);

        set<pair<int, int>> seen;
        seen.insert({dx, dy});

        for (int i = k; i < n; i++) {
            int addX = 0, addY = 0;
            delta(s[i], addX, addY);
            int remX = 0, remY = 0;
            delta(s[i - k], remX, remY);
            dx += addX - remX;
            dy += addY - remY;
            seen.insert({dx, dy});
        }
        return (int)seen.size();
    }
};
