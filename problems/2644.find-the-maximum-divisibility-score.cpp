// @leetcode id=2644 questionId=2694 slug=find-the-maximum-divisibility-score lang=cpp site=leetcode.com title="Find the Maximum Divisibility Score"
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int best = divisors[0], bestScore = -1;
        for (int d : divisors) {
            int score = 0;
            for (int x : nums) {
                if (x % d == 0) score++;
            }
            if (score > bestScore || (score == bestScore && d < best)) {
                bestScore = score;
                best = d;
            }
        }
        return best;
    }
};
