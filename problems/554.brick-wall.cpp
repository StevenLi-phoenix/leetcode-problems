// @leetcode id=554 questionId=554 slug=brick-wall lang=cpp site=leetcode.com title="Brick Wall"
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> gapCount;
        int n = wall.size();
        int best = 0;
        for (auto& row : wall) {
            long long pos = 0;
            for (size_t i = 0; i + 1 < row.size(); i++) {
                pos += row[i];
                best = max(best, ++gapCount[pos]);
            }
        }
        return n - best;
    }
};
