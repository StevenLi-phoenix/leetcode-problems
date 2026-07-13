// @leetcode id=3346 questionId=3622 slug=maximum-frequency-of-an-element-after-performing-operations-i lang=cpp site=leetcode.com title="Maximum Frequency of an Element After Performing Operations I"
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // For target value v = nums[i]: elements already equal to v need no
        // operation; elements within [v-k, v+k] but not equal to v can each
        // be shifted to v with exactly one operation (bounded by
        // numOperations). windowCount - cntEq gives how many "others" are
        // available to shift.
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = sorted.size();

        int best = 0;
        for (int i = 0; i < n; i++) {
            int v = sorted[i];
            int left = lower_bound(sorted.begin(), sorted.end(), v - k) - sorted.begin();
            int right = upper_bound(sorted.begin(), sorted.end(), v + k) - sorted.begin() - 1;
            int windowCount = right - left + 1;

            int eqLeft = lower_bound(sorted.begin(), sorted.end(), v) - sorted.begin();
            int eqRight = upper_bound(sorted.begin(), sorted.end(), v) - sorted.begin() - 1;
            int cntEq = eqRight - eqLeft + 1;

            int others = windowCount - cntEq;
            best = max(best, cntEq + min(numOperations, others));
        }

        // A window of elements all within 2k of each other can share SOME
        // common target (not necessarily an existing value); if the window
        // fits within numOperations, every element in it can be shifted
        // there regardless of how many already match, since no element
        // needs more than one operation.
        int l = 0;
        for (int r = 0; r < n; r++) {
            while (sorted[r] - sorted[l] > 2 * k) l++;
            int windowSize = r - l + 1;
            if (windowSize <= numOperations) best = max(best, windowSize);
        }
        return best;
    }
};
