// @leetcode id=2564 questionId=2700 slug=substring-xor-queries lang=cpp site=leetcode.com title="Substring XOR Queries"
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        unordered_map<long long, pair<int, int>> best; // value -> (left, right)
        int maxLen = min(n, 30);

        for (int len = 1; len <= maxLen; len++) {
            for (int i = 0; i + len <= n; i++) {
                long long val = 0;
                for (int k = i; k < i + len; k++) {
                    val = val * 2 + (s[k] - '0');
                }
                if (!best.count(val)) best[val] = {i, i + len - 1};
            }
        }

        vector<vector<int>> result;
        result.reserve(queries.size());
        for (auto& q : queries) {
            long long target = (long long)q[0] ^ (long long)q[1];
            auto it = best.find(target);
            if (it != best.end()) {
                result.push_back({it->second.first, it->second.second});
            } else {
                result.push_back({-1, -1});
            }
        }
        return result;
    }
};
