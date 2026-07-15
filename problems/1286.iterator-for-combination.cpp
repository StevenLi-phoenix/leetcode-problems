// @leetcode id=1286 questionId=1211 slug=iterator-for-combination lang=cpp site=leetcode.com title="Iterator for Combination"
class CombinationIterator {
private:
    vector<string> combos;
    size_t idx = 0;

public:
    CombinationIterator(string characters, int combinationLength) {
        int n = characters.size();
        string current;
        generate(characters, combinationLength, 0, current);
    }

    void generate(const string& chars, int len, int start, string& current) {
        if ((int)current.size() == len) {
            combos.push_back(current);
            return;
        }
        for (int i = start; i < (int)chars.size(); i++) {
            current.push_back(chars[i]);
            generate(chars, len, i + 1, current);
            current.pop_back();
        }
    }

    string next() {
        return combos[idx++];
    }

    bool hasNext() {
        return idx < combos.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
