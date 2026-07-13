// @leetcode id=2808 questionId=2920 slug=minimum-seconds-to-equalize-a-circular-array lang=cpp site=leetcode.com title="Minimum Seconds to Equalize a Circular Array"
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        // For each value, its occurrences act as simultaneously-expanding
        // seeds; the time to fill a circular gap of index-distance g
        // between two seeds is floor(g/2) (the g-1 empty cells between
        // them are closed from both sides at once). The best achievable
        // time for that value is its largest gap's requirement, and the
        // answer is the best value overall.
        int n = nums.size();
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; i++) positions[nums[i]].push_back(i);

        int best = INT_MAX;
        for (auto& [val, pos] : positions) {
            int maxGap = 0;
            int k = pos.size();
            for (int i = 0; i < k; i++) {
                int gap = (i + 1 < k) ? (pos[i + 1] - pos[i]) : (n - pos[k - 1] + pos[0]);
                maxGap = max(maxGap, gap);
            }
            int time = maxGap / 2;
            best = min(best, time);
        }
        return best;
    }
};
