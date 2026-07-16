// @leetcode id=1124 questionId=1219 slug=longest-well-performing-interval lang=cpp site=leetcode.com title="Longest Well-Performing Interval"
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> firstIdx;
        int score = 0;
        int best = 0;
        for (int i = 0; i < (int)hours.size(); i++) {
            score += (hours[i] > 8) ? 1 : -1;
            if (score > 0) {
                best = i + 1;
            } else {
                auto it = firstIdx.find(score - 1);
                if (it != firstIdx.end()) {
                    best = max(best, i - it->second);
                }
            }
            if (!firstIdx.count(score)) firstIdx[score] = i;
        }
        return best;
    }
};
