// @leetcode id=966 questionId=1006 slug=vowel-spellchecker lang=cpp site=leetcode.com title="Vowel Spellchecker"
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        auto toLower = [](string s) {
            for (char& c : s) c = tolower((unsigned char)c);
            return s;
        };
        auto devowel = [&](string s) {
            s = toLower(s);
            for (char& c : s) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') c = '*';
            }
            return s;
        };

        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        for (auto& w : wordlist) {
            string lw = toLower(w);
            if (!caseInsensitive.count(lw)) caseInsensitive[lw] = w;
            string dv = devowel(w);
            if (!vowelInsensitive.count(dv)) vowelInsensitive[dv] = w;
        }

        vector<string> result;
        for (auto& q : queries) {
            if (exact.count(q)) {
                result.push_back(q);
                continue;
            }
            string lq = toLower(q);
            if (caseInsensitive.count(lq)) {
                result.push_back(caseInsensitive[lq]);
                continue;
            }
            string dq = devowel(q);
            if (vowelInsensitive.count(dq)) {
                result.push_back(vowelInsensitive[dq]);
                continue;
            }
            result.push_back("");
        }
        return result;
    }
};
