// @leetcode id=447 questionId=447 slug=number-of-boomerangs lang=cpp site=leetcode.com title="Number of Boomerangs"
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        long long total = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> distCount;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                distCount[dx * dx + dy * dy]++;
            }
            for (auto& [dist, cnt] : distCount) total += (long long)cnt * (cnt - 1);
        }
        return (int)total;
    }
};
