// @leetcode id=658 questionId=658 slug=find-k-closest-elements lang=cpp site=leetcode.com title="Find K Closest Elements"
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = arr.size() - k;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};
