// @leetcode id=2717 questionId=2785 slug=semi-ordered-permutation lang=cpp site=leetcode.com title="Semi-Ordered Permutation"
class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos1 = -1, posN = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) pos1 = i;
            if (nums[i] == n) posN = i;
        }
        int moves = pos1 + (n - 1 - posN);
        // If 1 is after n, they cross each other, saving one move
        if (pos1 > posN) moves--;
        return moves;
    }
};
