// @leetcode id=1707 questionId=1826 slug=maximum-xor-with-an-element-from-array lang=cpp site=leetcode.com title="Maximum XOR With an Element From Array"
class Solution {
public:
    struct TrieNode {
        int child[2] = {-1, -1};
    };
    vector<TrieNode> trie;

    void insert(int num) {
        int node = 0;
        for (int bit = 29; bit >= 0; bit--) {
            int b = (num >> bit) & 1;
            if (trie[node].child[b] == -1) {
                trie.push_back(TrieNode());
                trie[node].child[b] = trie.size() - 1;
            }
            node = trie[node].child[b];
        }
    }

    int queryMaxXor(int x) {
        int node = 0;
        int result = 0;
        for (int bit = 29; bit >= 0; bit--) {
            int b = (x >> bit) & 1;
            int want = 1 - b;
            if (trie[node].child[want] != -1) {
                result |= (1 << bit);
                node = trie[node].child[want];
            } else {
                node = trie[node].child[b];
            }
        }
        return result;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int q = queries.size();

        vector<int> order(q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a][1] < queries[b][1];
        });

        trie.push_back(TrieNode());
        vector<int> answer(q, -1);

        int idx = 0;
        int n = nums.size();
        for (int qi : order) {
            int x = queries[qi][0], m = queries[qi][1];
            while (idx < n && nums[idx] <= m) {
                insert(nums[idx]);
                idx++;
            }
            if (idx == 0) {
                answer[qi] = -1;
            } else {
                answer[qi] = queryMaxXor(x);
            }
        }

        return answer;
    }
};
