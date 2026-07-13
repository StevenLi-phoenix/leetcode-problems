// @leetcode id=2683 questionId=2792 slug=neighboring-bitwise-xor lang=cpp site=leetcode.com title="Neighboring Bitwise XOR"
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for (int v : derived) x ^= v;
        return x == 0;
    }
};
