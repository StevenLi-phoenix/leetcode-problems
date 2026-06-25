// @leetcode id=1032 questionId=1097 slug=stream-of-characters lang=cpp site=leetcode.com title="Stream of Characters"
struct TrieNode {
    int children[26];
    bool isEnd;
    TrieNode() : isEnd(false) {
        fill(children, children + 26, -1);
    }
};

class StreamChecker {
    vector<TrieNode> trie;
    string stream;
    
    void insert(const string& word) {
        int cur = 0;
        for (int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';
            if (trie[cur].children[c] == -1) {
                trie[cur].children[c] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].children[c];
        }
        trie[cur].isEnd = true;
    }
    
public:
    StreamChecker(vector<string>& words) {
        trie.emplace_back();
        for (auto& w : words) insert(w);
    }
    
    bool query(char letter) {
        stream += letter;
        int cur = 0;
        for (int i = stream.size() - 1; i >= 0; i--) {
            int c = stream[i] - 'a';
            if (trie[cur].children[c] == -1) return false;
            cur = trie[cur].children[c];
            if (trie[cur].isEnd) return true;
        }
        return false;
    }
};
