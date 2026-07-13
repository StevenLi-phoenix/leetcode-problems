// @leetcode id=1040 questionId=1113 slug=moving-stones-until-consecutive-ii lang=cpp site=leetcode.com title="Moving Stones Until Consecutive II"
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();

        int maxMove = max(stones[n - 1] - stones[1], stones[n - 2] - stones[0]) - (n - 2);

        int minMove = INT_MAX;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (stones[i] - stones[j] > n - 1) j++;
            int count = i - j + 1;
            if (count == n - 1 && stones[i] - stones[j] == n - 2) {
                minMove = min(minMove, 2);
            } else {
                minMove = min(minMove, n - count);
            }
        }
        return {minMove, maxMove};
    }
};
