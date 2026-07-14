// @leetcode id=1125 questionId=1220 slug=smallest-sufficient-team lang=cpp site=leetcode.com title="Smallest Sufficient Team"
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size();
        unordered_map<string, int> skillIdx;
        for (int i = 0; i < m; i++) skillIdx[req_skills[i]] = i;

        int n = people.size();
        vector<int> personMask(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto& s : people[i]) personMask[i] |= (1 << skillIdx[s]);
        }

        int full = 1 << m;
        vector<long long> dp(full, -1); // bitmask of chosen people, -1 = unreachable
        vector<int> bestCount(full, INT_MAX);
        dp[0] = 0;
        bestCount[0] = 0;

        for (int mask = 0; mask < full; mask++) {
            if (bestCount[mask] == INT_MAX) continue;
            for (int p = 0; p < n; p++) {
                int nmask = mask | personMask[p];
                if (nmask == mask) continue;
                int ncount = bestCount[mask] + 1;
                if (ncount < bestCount[nmask]) {
                    bestCount[nmask] = ncount;
                    dp[nmask] = dp[mask] | (1LL << p);
                }
            }
        }

        vector<int> result;
        long long teamMask = dp[full - 1];
        for (int p = 0; p < n; p++) if (teamMask & (1LL << p)) result.push_back(p);
        return result;
    }
};
