// @leetcode id=2935 questionId=3197 slug=maximum-strong-pair-xor-ii lang=cpp site=leetcode.com title="Maximum Strong Pair XOR II"
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        // With x <= y, |x-y| <= min(x,y) reduces to y <= 2x. Sort
        // ascending; sliding a left pointer keeps a trie containing all
        // candidates x with 2x >= current y, then query max XOR with y.
        sort(nums.begin(), nums.end());
        int n = nums.size();
        const int BITS = 20;

        struct TrieNode {
            int child[2] = {-1, -1};
            int count = 0;
        };
        vector<TrieNode> trie(1);

        auto insert = [&](int val) {
            int node = 0;
            for (int b = BITS - 1; b >= 0; b--) {
                int bit = (val >> b) & 1;
                if (trie[node].child[bit] == -1) {
                    trie[node].child[bit] = trie.size();
                    trie.push_back(TrieNode());
                }
                node = trie[node].child[bit];
                trie[node].count++;
            }
        };
        auto remove = [&](int val) {
            int node = 0;
            for (int b = BITS - 1; b >= 0; b--) {
                int bit = (val >> b) & 1;
                node = trie[node].child[bit];
                trie[node].count--;
            }
        };
        auto queryMax = [&](int val) -> int {
            int node = 0, result = 0;
            for (int b = BITS - 1; b >= 0; b--) {
                int bit = (val >> b) & 1;
                int want = bit ^ 1;
                if (trie[node].child[want] != -1 && trie[trie[node].child[want]].count > 0) {
                    result |= (1 << b);
                    node = trie[node].child[want];
                } else {
                    node = trie[node].child[bit];
                }
            }
            return result;
        };

        int left = 0;
        int best = 0;
        for (int right = 0; right < n; right++) {
            while (2 * nums[left] < nums[right]) {
                remove(nums[left]);
                left++;
            }
            insert(nums[right]);
            best = max(best, queryMax(nums[right]));
        }
        return best;
    }
};
