// @leetcode id=394 questionId=394 slug=decode-string lang=cpp site=leetcode.com title="Decode String"
class Solution {
public:
    string decodeString(string s) {
        vector<int> countStack;
        vector<string> strStack;
        string current;
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push_back(num);
                strStack.push_back(current);
                num = 0;
                current.clear();
            } else if (c == ']') {
                int count = countStack.back();
                countStack.pop_back();
                string prev = strStack.back();
                strStack.pop_back();
                string repeated;
                for (int i = 0; i < count; ++i) repeated += current;
                current = prev + repeated;
            } else {
                current += c;
            }
        }
        return current;
    }
};
