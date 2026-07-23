// @leetcode id=3471 questionId=3705 slug=find-the-largest-almost-missing-integer lang=cpp site=leetcode.com title="Find the Largest Almost Missing Integer"
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int best = -1;

        vector<int> candidates(nums.begin(), nums.end());
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        for (int v : candidates) {
            int count = 0;
            for (int l = 0; l + k <= n; l++) {
                bool contains = false;
                for (int i = l; i < l + k; i++) {
                    if (nums[i] == v) { contains = true; break; }
                }
                if (contains) count++;
            }
            if (count == 1) best = max(best, v);
        }
        return best;
    }
};
