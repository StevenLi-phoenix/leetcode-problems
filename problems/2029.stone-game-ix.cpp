// @leetcode id=2029 questionId=2156 slug=stone-game-ix lang=cpp site=leetcode.com title="Stone Game IX"
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        for (int s : stones) cnt[s % 3]++;
        
        if (cnt[0] % 2 == 0) {
            // Even number of 0-stones: Alice wins iff both cnt[1] > 0 and cnt[2] > 0
            return cnt[1] > 0 && cnt[2] > 0;
        } else {
            // Odd number of 0-stones: Alice wins iff |cnt[1] - cnt[2]| > 2
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};
