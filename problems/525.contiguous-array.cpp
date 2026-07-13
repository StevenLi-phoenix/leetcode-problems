// @leetcode id=525 questionId=525 slug=contiguous-array lang=cpp site=leetcode.com title="Contiguous Array"
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex = {{0, -1}};
        int sum = 0, best = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            auto it = firstIndex.find(sum);
            if (it != firstIndex.end()) best = max(best, i - it->second);
            else firstIndex[sum] = i;
        }
        return best;
    }
};
