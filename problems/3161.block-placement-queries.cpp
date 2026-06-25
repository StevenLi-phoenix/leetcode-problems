// @leetcode id=3161 questionId=3435 slug=block-placement-queries lang=cpp site=leetcode.com title="Block Placement Queries"
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = queries.size();
        int maxVal = 0;
        for (auto& q : queries) {
            maxVal = max(maxVal, q[1]);
        }
        maxVal += 1;
        
        vector<int> bit(maxVal + 2, 0);
        
        auto update = [&](int i, int val) {
            for (i++; i < (int)bit.size(); i += i & (-i))
                bit[i] = max(bit[i], val);
        };
        
        auto queryMax = [&](int i) -> int {
            int res = 0;
            for (i++; i > 0; i -= i & (-i))
                res = max(res, bit[i]);
            return res;
        };
        
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(maxVal);
        
        for (auto& q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }
        
        {
            int prevPos = 0;
            for (auto it = next(obstacles.begin()); it != obstacles.end(); ++it) {
                int right = *it;
                int gap = right - prevPos;
                update(prevPos, gap);
                prevPos = right;
            }
        }
        
        vector<bool> tempAns(n, false);
        
        for (int i = n - 1; i >= 0; i--) {
            auto& q = queries[i];
            if (q[0] == 1) {
                int x = q[1];
                auto it = obstacles.find(x);
                auto nxt = next(it);
                auto prv = prev(it);
                int left = *prv;
                int right = *nxt;
                obstacles.erase(it);
                int gap = right - left;
                update(left, gap);
            } else {
                int x = q[1];
                int sz = q[2];
                if (sz > x) {
                    tempAns[i] = false;
                } else {
                    int prefMax = queryMax(x - sz);
                    tempAns[i] = prefMax >= sz;
                }
            }
        }
        
        vector<bool> answers;
        for (int i = 0; i < n; i++) {
            if (queries[i][0] == 2) {
                answers.push_back(tempAns[i]);
            }
        }
        
        return answers;
    }
};
