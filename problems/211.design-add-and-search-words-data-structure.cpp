// @leetcode id=211 questionId=211 slug=design-add-and-search-words-data-structure lang=cpp site=leetcode.com title="Design Add and Search Words Data Structure"
struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool searchHelper(TrieNode* node, const string& word, int pos) {
        if (!node) return false;
        if (pos == (int)word.size()) return node->isEnd;
        char c = word[pos];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchHelper(node->children[i], word, pos + 1)) return true;
            }
            return false;
        } else {
            return searchHelper(node->children[c - 'a'], word, pos + 1);
        }
    }

    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
