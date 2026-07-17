// @leetcode id=2876 questionId=3140 slug=count-visited-nodes-in-a-directed-graph lang=cpp site=leetcode.com title="Count Visited Nodes in a Directed Graph"
class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> color(n, 0); // 0 unvisited, 1 in current path, 2 finalized
        vector<int> answer(n, 0);
        vector<int> posInPath(n, -1);

        for (int start = 0; start < n; start++) {
            if (color[start] != 0) continue;

            vector<int> path;
            int cur = start;
            while (color[cur] == 0) {
                color[cur] = 1;
                posInPath[cur] = path.size();
                path.push_back(cur);
                cur = edges[cur];
            }

            if (color[cur] == 1) {
                int idx = posInPath[cur];
                int cycleLen = path.size() - idx;
                for (int i = idx; i < (int)path.size(); i++) {
                    answer[path[i]] = cycleLen;
                    color[path[i]] = 2;
                }
                for (int i = idx - 1; i >= 0; i--) {
                    answer[path[i]] = answer[path[i + 1]] + 1;
                    color[path[i]] = 2;
                }
            } else {
                int base = answer[cur];
                for (int i = (int)path.size() - 1; i >= 0; i--) {
                    base += 1;
                    answer[path[i]] = base;
                    color[path[i]] = 2;
                }
            }
        }

        return answer;
    }
};
