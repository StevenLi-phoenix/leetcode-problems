// @leetcode id=676 questionId=676 slug=implement-magic-dictionary lang=cpp site=leetcode.com title="Implement Magic Dictionary"
class MagicDictionary {
public:
    vector<string> words;

    MagicDictionary() {
    }

    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }

    bool search(string searchWord) {
        for (const string& w : words) {
            if (w.size() != searchWord.size()) continue;
            int diff = 0;
            for (size_t i = 0; i < w.size(); i++) {
                if (w[i] != searchWord[i]) diff++;
            }
            if (diff == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
