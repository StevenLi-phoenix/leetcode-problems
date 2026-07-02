// @leetcode id=3663 questionId=3994 slug=find-the-least-frequent-digit lang=cpp site=leetcode.com title="Find The Least Frequent Digit"
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int count[10] = {0};
        while (n > 0) {
            count[n % 10]++;
            n /= 10;
        }
        int best = -1;
        for (int d = 0; d < 10; d++) {
            if (count[d] == 0) continue;
            if (best == -1 || count[d] < count[best]) best = d;
        }
        return best;
    }
};
