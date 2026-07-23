// @leetcode id=1539 questionId=1646 slug=kth-missing-positive-number lang=cpp site=leetcode.com title="Kth Missing Positive Number"
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) lo = mid + 1;
            else hi = mid;
        }
        return lo + k;
    }
};
