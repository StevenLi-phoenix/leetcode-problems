// @leetcode id=1687 questionId=1789 slug=delivering-boxes-from-storage-to-ports lang=cpp site=leetcode.com title="Delivering Boxes from Storage to Ports"
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<long long> prefixWeight(n + 1, 0);
        for (int i = 0; i < n; i++) prefixWeight[i + 1] = prefixWeight[i] + boxes[i][1];

        vector<int> changesUpTo(n + 1, 0);
        for (int t = 2; t <= n; t++) {
            changesUpTo[t] = changesUpTo[t - 1] + (boxes[t - 1][0] != boxes[t - 2][0] ? 1 : 0);
        }

        vector<long long> dp(n + 1, 0);
        deque<pair<int, long long>> dq; // (j, dp[j] - changesUpTo[j+1])

        for (int i = 1; i <= n; i++) {
            int j = i - 1;
            long long val = dp[j] - changesUpTo[j + 1];
            while (!dq.empty() && dq.back().second >= val) dq.pop_back();
            dq.push_back({j, val});

            while (!dq.empty() && (i - dq.front().first > maxBoxes ||
                   prefixWeight[i] - prefixWeight[dq.front().first] > maxWeight)) {
                dq.pop_front();
            }

            dp[i] = 2 + changesUpTo[i] + dq.front().second;
        }

        return (int)dp[n];
    }
};
