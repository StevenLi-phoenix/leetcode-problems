// @leetcode id=888 questionId=924 slug=fair-candy-swap lang=cpp site=leetcode.com title="Fair Candy Swap"
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;
        for (int x : aliceSizes) sumA += x;
        for (int x : bobSizes) sumB += x;

        int diff = (sumB - sumA) / 2;

        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

        for (int y : aliceSizes) {
            int x = y + diff;
            if (bobSet.count(x)) {
                return {y, x};
            }
        }

        return {};
    }
};
