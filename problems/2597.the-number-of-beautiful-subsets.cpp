// @leetcode id=2597 questionId=2696 slug=the-number-of-beautiful-subsets lang=cpp site=leetcode.com title="The Number of Beautiful Subsets"
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> used;
        int count = 0;

        function<void(int)> backtrack = [&](int i) {
            if (i == (int)nums.size()) {
                count++; // count includes the empty subset; subtract it at the end
                return;
            }
            backtrack(i + 1); // skip nums[i]

            int v = nums[i];
            if (used[v - k] == 0 && used[v + k] == 0) {
                used[v]++;
                backtrack(i + 1);
                used[v]--;
            }
        };
        backtrack(0);
        return count - 1;
    }
};
