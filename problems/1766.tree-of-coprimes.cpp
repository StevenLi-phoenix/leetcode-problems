// @leetcode id=1766 questionId=1875 slug=tree-of-coprimes lang=cpp site=leetcode.com title="Tree of Coprimes"
class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int gcdTable[51][51];
        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                gcdTable[i][j] = std::__gcd(i, j);
            }
        }

        vector<pair<int,int>> lastSeen(51, {-1, -1});
        vector<int> ans(n, -1);

        struct Frame {
            int node, parent, depth, idx;
            int savedNode, savedDepth;
        };
        vector<Frame> stack;
        stack.reserve(n + 1);
        stack.push_back({0, -1, 0, 0, -1, -1});

        while (!stack.empty()) {
            Frame& f = stack.back();
            if (f.idx == 0) {
                int bestDepth = -1, bestNode = -1;
                for (int v = 1; v <= 50; v++) {
                    if (gcdTable[nums[f.node]][v] == 1 && lastSeen[v].second > bestDepth) {
                        bestDepth = lastSeen[v].second;
                        bestNode = lastSeen[v].first;
                    }
                }
                ans[f.node] = bestNode;

                f.savedNode = lastSeen[nums[f.node]].first;
                f.savedDepth = lastSeen[nums[f.node]].second;
                lastSeen[nums[f.node]] = {f.node, f.depth};
            }

            bool pushedChild = false;
            while (f.idx < (int)adj[f.node].size()) {
                int next = adj[f.node][f.idx];
                f.idx++;
                if (next != f.parent) {
                    stack.push_back({next, f.node, f.depth + 1, 0, -1, -1});
                    pushedChild = true;
                    break;
                }
            }
            if (pushedChild) continue;

            lastSeen[nums[f.node]] = {f.savedNode, f.savedDepth};
            stack.pop_back();
        }

        return ans;
    }
};
