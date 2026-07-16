// @leetcode id=3291 questionId=3559 slug=minimum-number-of-valid-strings-to-form-target-i lang=cpp site=leetcode.com title="Minimum Number of Valid Strings to Form Target I"
class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
    };

    TrieNode* root = new TrieNode();

    void insert(const string& w) {
        TrieNode* node = root;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
    }

    int minValidStrings(vector<string>& words, string target) {
        for (auto& w : words) insert(w);

        int n = target.size();
        vector<int> maxLen(n, 0);
        for (int i = 0; i < n; i++) {
            TrieNode* node = root;
            int len = 0;
            for (int j = i; j < n; j++) {
                int idx = target[j] - 'a';
                if (!node->children[idx]) break;
                node = node->children[idx];
                len++;
            }
            maxLen[i] = len;
        }

        int farthest = 0, segments = 0, curEnd = 0;
        for (int i = 0; i < n; i++) {
            if (i > farthest) return -1;
            farthest = max(farthest, i + maxLen[i]);
            if (i == curEnd) {
                if (curEnd >= n) break;
                segments++;
                curEnd = farthest;
                if (curEnd >= n) break;
            }
        }
        if (curEnd < n) return -1;
        return segments;
    }
};
