// @leetcode id=810 questionId=828 slug=chalkboard-xor-game lang=cpp site=leetcode.com title="Chalkboard XOR Game"
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        // Alice wins immediately if the XOR is already 0. Otherwise, if the
        // XOR is nonzero and the count is even, Alice can always mirror Bob's
        // move to keep the XOR nonzero and force Bob to take the losing turn.
        int total = 0;
        for (int x : nums) total ^= x;
        return total == 0 || nums.size() % 2 == 0;
    }
};
