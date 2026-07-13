// @leetcode id=2551 questionId=2681 slug=put-marbles-in-bags lang=cpp site=leetcode.com title="Put Marbles in Bags"
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // The first and last marble's weights are always counted once each
        // regardless of the split; every split point i contributes
        // weights[i]+weights[i+1] once. Choosing k bags means choosing
        // k-1 split points, so the max/min total scores are governed by
        // picking the k-1 largest/smallest adjacent-pair sums.
        int n = weights.size();
        if (k == 1) return 0;

        vector<long long> pairSums(n - 1);
        for (int i = 0; i < n - 1; i++) pairSums[i] = (long long)weights[i] + weights[i + 1];
        sort(pairSums.begin(), pairSums.end());

        long long minExtra = 0, maxExtra = 0;
        for (int i = 0; i < k - 1; i++) minExtra += pairSums[i];
        for (int i = 0; i < k - 1; i++) maxExtra += pairSums[n - 2 - i];

        return maxExtra - minExtra;
    }
};
