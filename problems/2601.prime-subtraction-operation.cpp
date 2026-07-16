// @leetcode id=2601 questionId=2716 slug=prime-subtraction-operation lang=cpp site=leetcode.com title="Prime Subtraction Operation"
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        const int MAXV = 1001;
        vector<bool> isComposite(MAXV + 1, false);
        for (int i = 2; i * i <= MAXV; i++) {
            if (!isComposite[i]) {
                for (int j = i * i; j <= MAXV; j += i) isComposite[j] = true;
            }
        }

        vector<int> bestPrimeBelow(MAXV + 2, 0);
        for (int x = 1; x <= MAXV + 1; x++) {
            bestPrimeBelow[x] = bestPrimeBelow[x - 1];
            if (x - 1 >= 2 && !isComposite[x - 1]) bestPrimeBelow[x] = x - 1;
        }

        int prev = 0;
        for (int num : nums) {
            int bound = num - prev;
            int p = (bound >= 0 && bound <= MAXV + 1) ? bestPrimeBelow[bound] : 0;
            int newVal = (p > 0) ? num - p : num;
            if (newVal <= prev) return false;
            prev = newVal;
        }
        return true;
    }
};
