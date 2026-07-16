// @leetcode id=648 questionId=648 slug=replace-words lang=cpp site=leetcode.com title="Replace Words"
class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };

    TrieNode* root = new TrieNode();

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    string findRoot(const string& word) {
        TrieNode* node = root;
        string prefix;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return word;
            prefix.push_back(c);
            node = node->children[idx];
            if (node->isEnd) return prefix;
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (auto& w : dictionary) insert(w);

        stringstream ss(sentence);
        string word;
        string result;
        bool first = true;
        while (ss >> word) {
            if (!first) result += " ";
            result += findRoot(word);
            first = false;
        }
        return result;
    }
};
