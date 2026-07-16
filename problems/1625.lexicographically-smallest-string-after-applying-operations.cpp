// @leetcode id=1625 questionId=1747 slug=lexicographically-smallest-string-after-applying-operations lang=cpp site=leetcode.com title="Lexicographically Smallest String After Applying Operations"
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        string best = s;

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            if (cur < best) best = cur;

            string added = cur;
            for (int i = 1; i < (int)added.size(); i += 2) {
                added[i] = '0' + (added[i] - '0' + a) % 10;
            }
            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }

            int n = cur.size();
            string rotated = cur.substr(n - b) + cur.substr(0, n - b);
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }
        return best;
    }
};
