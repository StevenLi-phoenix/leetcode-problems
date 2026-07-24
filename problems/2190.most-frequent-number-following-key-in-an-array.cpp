// @leetcode id=2190 questionId=2312 slug=most-frequent-number-following-key-in-an-array lang=cpp site=leetcode.com title="Most Frequent Number Following Key In an Array"
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> count;
        int best = -1, bestCount = -1;
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            if (nums[i] == key) {
                int target = nums[i + 1];
                int c = ++count[target];
                if (c > bestCount) {
                    bestCount = c;
                    best = target;
                }
            }
        }
        return best;
    }
};
