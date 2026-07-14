// @leetcode id=2359 questionId=2438 slug=find-closest-node-to-given-two-nodes lang=cpp site=leetcode.com title="Find Closest Node to Given Two Nodes"
class Solution {
public:
    vector<int> distancesFrom(vector<int>& edges, int start) {
        int n = edges.size();
        vector<int> dist(n, -1);
        int cur = start, d = 0;
        while (cur != -1 && dist[cur] == -1) {
            dist[cur] = d++;
            cur = edges[cur];
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> d1 = distancesFrom(edges, node1);
        vector<int> d2 = distancesFrom(edges, node2);

        int best = -1, bestMax = INT_MAX;
        for (int i = 0; i < (int)edges.size(); i++) {
            if (d1[i] == -1 || d2[i] == -1) continue;
            int m = max(d1[i], d2[i]);
            if (m < bestMax) { bestMax = m; best = i; }
        }
        return best;
    }
};
