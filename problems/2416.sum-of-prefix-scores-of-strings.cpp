// @leetcode id=2416 questionId=2494 slug=sum-of-prefix-scores-of-strings lang=cpp site=leetcode.com title="Sum of Prefix Scores of Strings"
class Solution {
public:
    struct TrieNode {
        int cnt = 0;
        TrieNode* children[26] = {};
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        // Build trie
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
                node->cnt++;
            }
        }
        
        // Query for each word
        int n = words.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            TrieNode* node = root;
            int score = 0;
            for (char c : words[i]) {
                int idx = c - 'a';
                node = node->children[idx];
                score += node->cnt;
            }
            ans[i] = score;
        }
        
        return ans;
    }
};
