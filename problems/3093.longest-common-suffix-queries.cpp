// @leetcode id=3093 questionId=3376 slug=longest-common-suffix-queries lang=cpp site=leetcode.com title="Longest Common Suffix Queries"
class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        int bestIdx;
        TrieNode() : bestIdx(-1) {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
        ~TrieNode() {
            for (int i = 0; i < 26; i++) delete children[i];
        }
    };

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        int n = wordsContainer.size();

        // Insert reversed strings into Trie
        for (int i = 0; i < n; i++) {
            string& w = wordsContainer[i];
            TrieNode* node = root;
            // Update root's best index
            if (node->bestIdx == -1 ||
                wordsContainer[i].size() < wordsContainer[node->bestIdx].size()) {
                node->bestIdx = i;
            }
            // Traverse reversed string
            for (int j = w.size() - 1; j >= 0; j--) {
                int c = w[j] - 'a';
                if (!node->children[c]) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
                // Update best index at this node
                if (node->bestIdx == -1 ||
                    wordsContainer[i].size() < wordsContainer[node->bestIdx].size()) {
                    node->bestIdx = i;
                }
            }
        }

        // Query
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (auto& q : wordsQuery) {
            TrieNode* node = root;
            for (int j = q.size() - 1; j >= 0; j--) {
                int c = q[j] - 'a';
                if (!node->children[c]) break;
                node = node->children[c];
            }
            ans.push_back(node->bestIdx);
        }

        delete root;
        return ans;
    }
};
