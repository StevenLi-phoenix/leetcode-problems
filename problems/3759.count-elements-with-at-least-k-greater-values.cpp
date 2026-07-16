// @leetcode id=3759 questionId=4141 slug=count-elements-with-at-least-k-greater-values lang=cpp site=leetcode.com title="Count Elements With at Least K Greater Values"
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = sorted.size();
        int count = 0;
        for (int x : nums) {
            int greater = n - (upper_bound(sorted.begin(), sorted.end(), x) - sorted.begin());
            if (greater >= k) count++;
        }
        return count;
    }
};
