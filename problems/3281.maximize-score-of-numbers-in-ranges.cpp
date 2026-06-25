// @leetcode id=3281 questionId=3485 slug=maximize-score-of-numbers-in-ranges lang=cpp site=leetcode.com title="Maximize Score of Numbers in Ranges"
class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(), start.end());
        
        // Binary search on the minimum difference (answer)
        auto canAchieve = [&](long long minDiff) -> bool {
            long long prev = start[0]; // pick start[0] as first number
            for (int i = 1; i < n; i++) {
                long long next = prev + minDiff;
                // next must be in [start[i], start[i]+d]
                if (next > (long long)start[i] + d) return false;
                prev = max(next, (long long)start[i]);
            }
            return true;
        };
        
        long long lo = 0, hi = (long long)start[n-1] + d - start[0];
        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;
            if (canAchieve(mid)) lo = mid;
            else hi = mid - 1;
        }
        return (int)lo;
    }
};
