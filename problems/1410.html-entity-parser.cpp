// @leetcode id=1410 questionId=1526 slug=html-entity-parser lang=cpp site=leetcode.com title="HTML Entity Parser"
class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> mp = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };
        
        string res;
        int i = 0;
        while (i < (int)text.size()) {
            if (text[i] == '&') {
                bool found = false;
                for (auto& [entity, ch] : mp) {
                    if (text.substr(i, entity.size()) == entity) {
                        res += ch;
                        i += entity.size();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    res += text[i++];
                }
            } else {
                res += text[i++];
            }
        }
        return res;
    }
};
