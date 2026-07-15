// @leetcode id=2998 questionId=3239 slug=minimum-number-of-operations-to-make-x-and-y-equal lang=cpp site=leetcode.com title="Minimum Number of Operations to Make X and Y Equal"
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x == y) return 0;
        if (x < y) return y - x;

        int upperBound = x + 5;
        vector<int> dist(upperBound + 1, -1);
        queue<int> q;
        dist[x] = 0;
        q.push(x);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == y) return dist[cur];
            vector<int> nexts;
            if (cur % 11 == 0) nexts.push_back(cur / 11);
            if (cur % 5 == 0) nexts.push_back(cur / 5);
            nexts.push_back(cur - 1);
            if (cur + 1 <= upperBound) nexts.push_back(cur + 1);
            for (int nxt : nexts) {
                if (nxt >= 0 && nxt <= upperBound && dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        return dist[y];
    }
};
