// @leetcode id=2374 questionId=2455 slug=node-with-highest-edge-score lang=cpp site=leetcode.com title="Node With Highest Edge Score"
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n, 0);
        for (int i = 0; i < n; i++) score[edges[i]] += i;

        int best = 0;
        for (int i = 1; i < n; i++) {
            if (score[i] > score[best]) best = i;
        }
        return best;
    }
};
