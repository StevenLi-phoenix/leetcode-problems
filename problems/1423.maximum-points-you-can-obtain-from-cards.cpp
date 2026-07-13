// @leetcode id=1423 questionId=1538 slug=maximum-points-you-can-obtain-from-cards lang=cpp site=leetcode.com title="Maximum Points You Can Obtain from Cards"
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // Taking k cards from the ends leaves a contiguous middle window of
        // size n-k untaken; maximizing the taken sum is the same as
        // minimizing that middle window's sum.
        int n = cardPoints.size();
        int windowSize = n - k;
        int total = 0;
        for (int v : cardPoints) total += v;
        if (windowSize == 0) return total;

        int windowSum = 0;
        for (int i = 0; i < windowSize; i++) windowSum += cardPoints[i];

        int minWindow = windowSum;
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindow = min(minWindow, windowSum);
        }
        return total - minWindow;
    }
};
