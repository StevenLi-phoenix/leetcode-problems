// @leetcode id=912 questionId=948 slug=sort-an-array lang=cpp site=leetcode.com title="Sort an Array"
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> buf(nums.size());
        mergeSort(nums, buf, 0, (int)nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int>& a, vector<int>& buf, int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(a, buf, lo, mid);
        mergeSort(a, buf, mid + 1, hi);
        int i = lo, j = mid + 1, k = lo;
        while (i <= mid && j <= hi) buf[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
        while (i <= mid) buf[k++] = a[i++];
        while (j <= hi) buf[k++] = a[j++];
        for (int p = lo; p <= hi; p++) a[p] = buf[p];
    }
};
