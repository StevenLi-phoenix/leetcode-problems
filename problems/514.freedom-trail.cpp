// @leetcode id=514 questionId=514 slug=freedom-trail lang=cpp site=leetcode.com title="Freedom Trail"
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> positions(26);
        for (int i = 0; i < n; i++) positions[ring[i] - 'a'].push_back(i);

        vector<int> dp = {0};
        vector<int> curPositions = {0};

        for (int k = 0; k < m; k++) {
            auto& nextPositions = positions[key[k] - 'a'];
            vector<int> ndp(nextPositions.size(), INT_MAX);

            for (size_t j = 0; j < nextPositions.size(); j++) {
                for (size_t i = 0; i < curPositions.size(); i++) {
                    int dist = abs(nextPositions[j] - curPositions[i]);
                    int step = min(dist, n - dist);
                    ndp[j] = min(ndp[j], dp[i] + step + 1);
                }
            }

            dp = ndp;
            curPositions = nextPositions;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
