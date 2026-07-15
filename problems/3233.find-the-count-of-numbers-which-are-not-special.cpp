// @leetcode id=3233 questionId=3507 slug=find-the-count-of-numbers-which-are-not-special lang=cpp site=leetcode.com title="Find the Count of Numbers Which Are Not Special"
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        long long lo = (long long)ceil(sqrt((double)l));
        while (lo * lo < l) lo++;
        while (lo > 1 && (lo - 1) * (lo - 1) >= l) lo--;

        long long hi = (long long)floor(sqrt((double)r));
        while (hi * hi > r) hi--;
        while ((hi + 1) * (hi + 1) <= r) hi++;

        int maxP = (int)hi;
        vector<bool> isComposite(maxP + 1, false);
        int specialCount = 0;
        for (long long p = 2; p <= maxP; p++) {
            if (!isComposite[p]) {
                if (p >= lo && p <= hi) specialCount++;
                for (long long m = p * p; m <= maxP; m += p) isComposite[m] = true;
            }
        }

        long long total = (long long)r - l + 1;
        return (int)(total - specialCount);
    }
};
