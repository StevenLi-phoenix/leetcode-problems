// @leetcode id=1343 questionId=1445 slug=number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold lang=cpp site=leetcode.com title="Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold"
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long need = (long long)threshold * k;
        long long sum = 0;
        int n = arr.size();
        for (int i = 0; i < k; i++) sum += arr[i];

        int count = 0;
        if (sum >= need) count++;
        for (int i = k; i < n; i++) {
            sum += arr[i] - arr[i - k];
            if (sum >= need) count++;
        }
        return count;
    }
};
