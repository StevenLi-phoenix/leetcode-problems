// @leetcode id=2009 questionId=2119 slug=minimum-number-of-operations-to-make-array-continuous lang=cpp site=leetcode.com title="Minimum Number of Operations to Make Array Continuous"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> uniq = nums;
        sort(uniq.begin(), uniq.end());
        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

        // For each left endpoint, find how many unique values fall within
        // [uniq[left], uniq[left] + n - 1]; those can stay, the rest of the
        // array gets replaced.
        int best = 0;
        int right = 0;
        for (int left = 0; left < (int)uniq.size(); left++) {
            right = max(right, left);
            while (right < (int)uniq.size() && uniq[right] < uniq[left] + n) right++;
            best = max(best, right - left);
        }
        return n - best;
    }
};
