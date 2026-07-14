// @leetcode id=649 questionId=649 slug=dota2-senate lang=cpp site=leetcode.com title="Dota2 Senate"
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') r.push(i);
            else d.push(i);
        }

        while (!r.empty() && !d.empty()) {
            int ri = r.front(); r.pop();
            int di = d.front(); d.pop();
            if (ri < di) r.push(ri + n);
            else d.push(di + n);
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};
