// @leetcode id=2555 questionId=2673 slug=maximize-win-from-two-segments lang=cpp site=leetcode.com title="Maximize Win From Two Segments"
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> best(n, 0);
        int left = 0, ans = 0;

        for (int right = 0; right < n; ++right) {
            while (prizePositions[right] - prizePositions[left] > k) ++left;
            int cnt = right - left + 1;
            int prevBest = (left > 0) ? best[left - 1] : 0;
            ans = max(ans, cnt + prevBest);
            best[right] = (right > 0) ? max(best[right - 1], cnt) : cnt;
        }
        return ans;
    }
};
