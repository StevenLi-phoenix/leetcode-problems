// @leetcode id=3630 questionId=3882 slug=partition-array-for-maximum-xor-and-and lang=cpp site=leetcode.com title="Partition Array for Maximum XOR and AND"
class Solution {
public:
    long long maximizeXorAndXor(vector<int>& nums) {
        int n = nums.size();
        long long best = 0;

        long long rElems[20];
        int order[30];
        long long basis[30];

        for (int mask = 0; mask < (1 << n); mask++) {
            long long andB = -1;
            bool hasB = false;
            long long full = 0;
            int rCount = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (!hasB) {
                        andB = nums[i];
                        hasB = true;
                    } else {
                        andB &= nums[i];
                    }
                } else {
                    full ^= nums[i];
                    rElems[rCount++] = nums[i];
                }
            }

            if (!hasB) andB = 0;

            long long relevantMask = (~full) & ((1LL << 30) - 1);

            int oc = 0;
            for (int b = 29; b >= 0; b--) if ((relevantMask >> b) & 1) order[oc++] = b;
            for (int b = 29; b >= 0; b--) if (!((relevantMask >> b) & 1)) order[oc++] = b;

            for (int i = 0; i < 30; i++) basis[i] = 0;
            for (int idx = 0; idx < rCount; idx++) {
                long long v = rElems[idx];
                for (int pos = 0; pos < 30; pos++) {
                    int b = order[pos];
                    if (!((v >> b) & 1)) continue;
                    if (basis[pos] == 0) {
                        basis[pos] = v;
                        break;
                    }
                    v ^= basis[pos];
                }
            }

            long long candidate = 0;
            for (int pos = 0; pos < 30; pos++) {
                if (basis[pos] == 0) continue;
                long long withV = candidate ^ basis[pos];
                if ((withV & relevantMask) > (candidate & relevantMask)) {
                    candidate = withV;
                }
            }

            long long fVal = candidate + (candidate ^ full);
            long long total = andB + fVal;
            best = max(best, total);
        }

        return best;
    }
};
