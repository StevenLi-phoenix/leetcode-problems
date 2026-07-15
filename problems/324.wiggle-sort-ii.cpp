// @leetcode id=324 questionId=324 slug=wiggle-sort-ii lang=cpp site=leetcode.com title="Wiggle Sort II"
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int mid = (n + 1) / 2;
        int lo = mid - 1, hi = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sorted[lo--];
            } else {
                nums[i] = sorted[hi--];
            }
        }
    }
};
