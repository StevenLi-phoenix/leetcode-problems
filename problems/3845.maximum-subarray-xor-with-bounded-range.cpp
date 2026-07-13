// @leetcode id=3845 questionId=4204 slug=maximum-subarray-xor-with-bounded-range lang=cpp site=leetcode.com title="Maximum Subarray XOR with Bounded Range"
class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        // Two-pointer maintains the widest window [l, r] with max-min <= k
        // (monotonic deques). For each r, valid subarray starts are
        // exactly a in [l, r]; maintain a count-trie of prefix[a] for that
        // range so it can be queried for the max XOR against prefix[r+1].
        const int BITS = 16; // nums[i] < 2^15, prefix values stay < 2^15
        int n = nums.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] ^ nums[i];

        struct TrieNode {
            int child[2] = {-1, -1};
            int count = 0;
        };
        vector<TrieNode> trie(1);

        auto insert = [&](int val, int delta) {
            int node = 0;
            for (int b = BITS - 1; b >= 0; b--) {
                int bit = (val >> b) & 1;
                if (trie[node].child[bit] == -1) {
                    trie[node].child[bit] = trie.size();
                    trie.push_back(TrieNode());
                }
                node = trie[node].child[bit];
                trie[node].count += delta;
            }
        };

        auto queryMax = [&](int val) -> int {
            int node = 0;
            int result = 0;
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

        deque<int> maxDq, minDq;
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[r]) maxDq.pop_back();
            maxDq.push_back(r);
            while (!minDq.empty() && nums[minDq.back()] >= nums[r]) minDq.pop_back();
            minDq.push_back(r);

            while (nums[maxDq.front()] - nums[minDq.front()] > k) {
                insert(prefix[l], -1);
                l++;
                if (maxDq.front() < l) maxDq.pop_front();
                if (minDq.front() < l) minDq.pop_front();
            }

            insert(prefix[r], 1);
            ans = max(ans, queryMax(prefix[r + 1]));
        }
        return ans;
    }
};
