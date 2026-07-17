// @leetcode id=3244 questionId=3514 slug=shortest-distance-after-road-addition-queries-ii lang=cpp site=leetcode.com title="Shortest Distance After Road Addition Queries II"
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> essential;
        for (int i = 0; i < n; i++) essential.insert(i);

        vector<int> answer;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            auto lo = essential.upper_bound(u);
            auto hi = essential.lower_bound(v);
            essential.erase(lo, hi);
            answer.push_back((int)essential.size() - 1);
        }

        return answer;
    }
};
