// @leetcode id=3041 questionId=3298 slug=maximize-consecutive-elements-in-an-array-after-modification lang=cpp site=leetcode.com title="Maximize Consecutive Elements in an Array After Modification"
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> cnt(maxVal + 2, 0);
        for (int v : nums) cnt[v]++;

        // A[v] = best chain ending at v where slot v is filled by v's own
        // original value (consumes one of cnt[v]).
        // B[v] = best chain ending at v where slot v is filled by
        // incrementing a v-1 original (cnt[v] itself stays fully available
        // to bridge further into v+1).
        // Both default to 0 when not achievable, doubling as the "chain
        // hasn't started yet" baseline.
        int prevA = 0, prevB = 0;
        int ans = 0;
        for (int v = 1; v <= maxVal + 1; v++) {
            int a = cnt[v] >= 1 ? 1 + max(prevA, prevB) : 0;
            int b = 0;
            int cntPrev = (v - 1 >= 0 && v - 1 <= maxVal + 1) ? cnt[v - 1] : 0;
            if (cntPrev >= 1) b = max(b, 1 + prevB);
            if (cntPrev >= 2) b = max(b, 1 + prevA);
            ans = max({ans, a, b});
            prevA = a;
            prevB = b;
        }
        return ans;
    }
};
