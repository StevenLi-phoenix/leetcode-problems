// @leetcode id=3547 questionId=3845 slug=maximum-sum-of-edge-values-in-a-graph lang=cpp site=leetcode.com title="Maximum Sum of Edge Values in a Graph"
class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        bool isCycle = (m == n);

        deque<long long> dq;
        dq.push_back(n);
        for (long long v = n - 1; v >= 1; v--) {
            long long frontProduct = v * dq.front();
            long long backProduct = v * dq.back();
            if (frontProduct >= backProduct) dq.push_front(v);
            else dq.push_back(v);
        }

        long long total = 0;
        for (int i = 0; i + 1 < (int)dq.size(); i++) {
            total += dq[i] * dq[i + 1];
        }
        if (isCycle) {
            total += dq.front() * dq.back();
        }
        return total;
    }
};
