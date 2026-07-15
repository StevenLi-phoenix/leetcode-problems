// @leetcode id=2768 questionId=2889 slug=number-of-black-blocks lang=cpp site=leetcode.com title="Number of Black Blocks"
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long, int> blockCount;
        auto key = [&](long long x, long long y) { return x * (n + 1) + y; };

        for (auto& c : coordinates) {
            int x = c[0], y = c[1];
            for (int dx = -1; dx <= 0; dx++) {
                for (int dy = -1; dy <= 0; dy++) {
                    int bx = x + dx, by = y + dy;
                    if (bx < 0 || by < 0 || bx > m - 2 || by > n - 2) continue;
                    blockCount[key(bx, by)]++;
                }
            }
        }

        long long totalBlocks = (long long)(m - 1) * (n - 1);
        vector<long long> result(5, 0);
        long long accountedNonZero = 0;
        for (auto& [k, cnt] : blockCount) {
            result[cnt]++;
            accountedNonZero++;
        }
        result[0] = totalBlocks - accountedNonZero;
        return result;
    }
};
