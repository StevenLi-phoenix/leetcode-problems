// @leetcode id=3486 questionId=3798 slug=longest-special-path-ii lang=cpp site=leetcode.com title="Longest Special Path II"
class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> distArr(n, 0);
        vector<int> depthOf(n, 0);

        unordered_map<int,int> last;
        int lo = -1;
        int dupFirst = -1;

        long long bestLen = 0;
        int bestNodes = 1;

        struct Frame {
            int node;
            int parent;
            size_t childIdx;
            int savedLastVal;
            bool savedLastExisted;
            int savedLo;
            int savedDup;
        };

        vector<Frame> stk;
        depthOf[0] = 0;
        distArr[0] = 0;

        auto enterNode = [&](int node) {
            int val = nums[node];
            bool existed = last.count(val) > 0;
            int savedVal = existed ? last[val] : -1;

            int savedLo = lo;
            int savedDup = dupFirst;

            int p = existed ? last[val] : -1;
            if (p > lo) {
                if (dupFirst == -1) {
                    dupFirst = p;
                } else if (p < dupFirst) {
                    lo = p;
                    // dupFirst stays (old duplicate remains active)
                } else {
                    lo = dupFirst;
                    dupFirst = p;
                }
            }
            last[val] = depthOf[node];

            long long baseDist = distArr[lo + 1];
            long long curLen = distArr[depthOf[node]] - baseDist;
            int curNodes = depthOf[node] - lo;

            if (curLen > bestLen || (curLen == bestLen && curNodes < bestNodes)) {
                bestLen = curLen;
                bestNodes = curNodes;
            }

            return Frame{node, -1, 0, savedVal, existed, savedLo, savedDup};
        };

        Frame rootFrame = enterNode(0);
        rootFrame.parent = -1;
        stk.push_back(rootFrame);

        while (!stk.empty()) {
            Frame& top = stk.back();
            int node = top.node;
            bool advanced = false;

            while (top.childIdx < adj[node].size()) {
                auto [child, w] = adj[node][top.childIdx];
                top.childIdx++;
                if (child == top.parent) continue;

                depthOf[child] = depthOf[node] + 1;
                distArr[depthOf[child]] = distArr[depthOf[node]] + w;

                Frame childFrame = enterNode(child);
                childFrame.parent = node;
                stk.push_back(childFrame);
                advanced = true;
                break;
            }

            if (!advanced) {
                int val = nums[node];
                if (top.savedLastExisted) {
                    last[val] = top.savedLastVal;
                } else {
                    last.erase(val);
                }
                lo = top.savedLo;
                dupFirst = top.savedDup;
                stk.pop_back();
            }
        }

        return {(int)bestLen, bestNodes};
    }
};
