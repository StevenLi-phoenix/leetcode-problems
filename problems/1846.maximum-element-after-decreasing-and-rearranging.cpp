// @leetcode id=1846 questionId=1956 slug=maximum-element-after-decreasing-and-rearranging lang=cpp site=leetcode.com title="Maximum Element After Decreasing and Rearranging"
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
            arr[i] = min(arr[i], arr[i-1] + 1);
        }
        return arr[n-1];
    }
};
