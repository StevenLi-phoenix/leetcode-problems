// @leetcode id=3425 questionId=3687 slug=longest-special-path lang=cpp site=leetcode.com title="Longest Special Path"
class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> adj(n); // (neighbor, weight)
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> last(maxVal + 1, -1);
        vector<long long> dist(n + 1, 0); // dist[d+1] = distance from root to the node at depth d; dist[0] = virtual depth -1
        int left = -1; // depth index (0-based); window is (left, depth]

        long long bestLen = -1;
        long long bestNodes = 0;

        auto distAt = [&](int depth) -> long long { return dist[depth + 1]; };

        // Explicit-stack DFS: entries are either "enter" (process node, push children)
        // or "exit" (undo state mutated by this node before returning to its parent).
        struct EnterFrame { int node, parent, depth; long long distSoFar; };

        vector<char> opStack;
        vector<EnterFrame> enterStack;
        vector<array<int, 3>> exitStack; // oldLeft, oldLastVal, val

        opStack.push_back('E');
        enterStack.push_back({0, -1, 0, 0});

        while (!opStack.empty()) {
            char op = opStack.back(); opStack.pop_back();
            if (op == 'E') {
                EnterFrame f = enterStack.back(); enterStack.pop_back();
                dist[f.depth + 1] = f.distSoFar;
                int val = nums[f.node];
                int oldLeft = left;
                int oldLastVal = last[val];
                if (last[val] > left) left = last[val];
                last[val] = f.depth;

                // The path starts at depth left+1 (the excluded node is at
                // depth left), so its length is measured from that starting
                // node's own distance, not the excluded ancestor's.
                long long length = distAt(f.depth) - distAt(left + 1);
                long long nodeCount = f.depth - left;
                if (length > bestLen || (length == bestLen && nodeCount < bestNodes)) {
                    bestLen = length;
                    bestNodes = nodeCount;
                }

                opStack.push_back('X');
                exitStack.push_back({oldLeft, oldLastVal, val});

                for (auto& [nb, w] : adj[f.node]) {
                    if (nb == f.parent) continue;
                    opStack.push_back('E');
                    enterStack.push_back({nb, f.node, f.depth + 1, f.distSoFar + w});
                }
            } else {
                auto& e = exitStack.back();
                left = e[0];
                last[e[2]] = e[1];
                exitStack.pop_back();
            }
        }

        return {(int)bestLen, (int)bestNodes};
    }
};
