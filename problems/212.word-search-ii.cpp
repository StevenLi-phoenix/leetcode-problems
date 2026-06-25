// @leetcode id=212 questionId=212 slug=word-search-ii lang=cpp site=leetcode.com title="Word Search II"
struct TrieNode {
    TrieNode* children[26];
    string word;
    TrieNode() : word("") {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution {
public:
    vector<string> result;
    
    void insert(TrieNode* root, const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->word = word;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        
        TrieNode* next = node->children[c - 'a'];
        if (!next->word.empty()) {
            result.push_back(next->word);
            next->word = ""; // avoid duplicates
        }
        
        board[i][j] = '#'; // mark visited
        int m = board.size(), n = board[0].size();
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                dfs(board, ni, nj, next);
            }
        }
        board[i][j] = c; // restore
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) insert(root, w);
        
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }
        
        return result;
    }
};
