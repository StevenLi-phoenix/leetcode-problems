// @leetcode id=591 questionId=591 slug=tag-validator lang=cpp site=leetcode.com title="Tag Validator"
class Solution {
public:
    bool isValid(string code) {
        int n = code.size();
        if (code[0] != '<') return false;
        vector<string> stack;
        int i = 0;

        auto validName = [](const string& s) {
            if (s.empty() || s.size() > 9) return false;
            for (char c : s) if (!isupper(c)) return false;
            return true;
        };

        while (i < n) {
            if (stack.empty() && i > 0) return false;

            if (code[i] == '<') {
                if (i + 1 < n && code[i + 1] == '/') {
                    int j = code.find('>', i + 2);
                    if (j == (int)string::npos) return false;
                    string name = code.substr(i + 2, j - (i + 2));
                    if (!validName(name)) return false;
                    if (stack.empty() || stack.back() != name) return false;
                    stack.pop_back();
                    i = j + 1;
                    if (stack.empty() && i != n) return false;
                } else if (code.compare(i, 9, "<![CDATA[") == 0) {
                    if (stack.empty()) return false;
                    int j = code.find("]]>", i + 9);
                    if (j == (int)string::npos) return false;
                    i = j + 3;
                } else {
                    int j = code.find('>', i + 1);
                    if (j == (int)string::npos) return false;
                    string name = code.substr(i + 1, j - (i + 1));
                    if (!validName(name)) return false;
                    stack.push_back(name);
                    i = j + 1;
                }
            } else {
                if (stack.empty()) return false;
                i++;
            }
        }

        return stack.empty();
    }
};
