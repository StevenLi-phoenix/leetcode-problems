// @leetcode id=1601 questionId=1723 slug=maximum-number-of-achievable-transfer-requests lang=cpp site=leetcode.com title="Maximum Number of Achievable Transfer Requests"
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int best = 0;

        for (int mask = 0; mask < (1 << m); mask++) {
            vector<int> net(n, 0);
            int count = __builtin_popcount(mask);
            if (count <= best) continue;

            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    net[requests[i][0]]--;
                    net[requests[i][1]]++;
                }
            }

            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (net[i] != 0) { valid = false; break; }
            }

            if (valid) best = count;
        }

        return best;
    }
};
