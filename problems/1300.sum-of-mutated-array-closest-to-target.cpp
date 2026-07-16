// @leetcode id=1300 questionId=1232 slug=sum-of-mutated-array-closest-to-target lang=cpp site=leetcode.com title="Sum of Mutated Array Closest to Target"
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        auto computeSum = [&](int value) {
            long long sum = 0;
            for (int x : arr) sum += min(x, value);
            return sum;
        };

        int lo = 0, hi = *max_element(arr.begin(), arr.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (computeSum(mid) >= target) hi = mid;
            else lo = mid + 1;
        }

        if (lo == 0) return 0;
        long long diffLo = llabs(computeSum(lo) - target);
        long long diffPrev = llabs(computeSum(lo - 1) - target);
        return diffPrev <= diffLo ? lo - 1 : lo;
    }
};
