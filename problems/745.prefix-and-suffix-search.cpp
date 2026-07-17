// @leetcode id=745 questionId=746 slug=prefix-and-suffix-search lang=cpp site=leetcode.com title="Prefix and Suffix Search"
class WordFilter {
public:
    unordered_map<string, int> combo;

    WordFilter(vector<string>& words) {
        for (int idx = 0; idx < (int)words.size(); idx++) {
            string& w = words[idx];
            int n = w.size();
            for (int p = 0; p <= n; p++) {
                for (int s = 0; s <= n; s++) {
                    string key = w.substr(0, p) + "#" + w.substr(n - s);
                    combo[key] = idx;
                }
            }
        }
    }

    int f(string pref, string suff) {
        auto it = combo.find(pref + "#" + suff);
        return it != combo.end() ? it->second : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
