// @leetcode id=421 questionId=421 slug=maximum-xor-of-two-numbers-in-an-array lang=cpp site=leetcode.com title="Maximum XOR of Two Numbers in an Array"
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // Binary trie over 31 bits (nums[i] <= 2^31-1); for each number,
        // greedily walk toward the opposite bit at each level to maximize XOR.
        struct Node { Node* child[2] = {nullptr, nullptr}; };
        Node root;

        auto insert = [&](int x) {
            Node* cur = &root;
            for (int b = 30; b >= 0; b--) {
                int bit = (x >> b) & 1;
                if (!cur->child[bit]) cur->child[bit] = new Node();
                cur = cur->child[bit];
            }
        };
        auto queryBest = [&](int x) {
            Node* cur = &root;
            int result = 0;
            for (int b = 30; b >= 0; b--) {
                int bit = (x >> b) & 1;
                int want = 1 - bit;
                if (cur->child[want]) {
                    result |= (1 << b);
                    cur = cur->child[want];
                } else {
                    cur = cur->child[bit];
                }
            }
            return result;
        };

        for (int x : nums) insert(x);
        int ans = 0;
        for (int x : nums) ans = max(ans, queryBest(x));
        return ans;
    }
};
