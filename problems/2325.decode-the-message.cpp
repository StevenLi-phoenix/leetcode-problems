// @leetcode id=2325 questionId=2406 slug=decode-the-message lang=cpp site=leetcode.com title="Decode the Message"
class Solution {
public:
    string decodeMessage(string key, string message) {
        char table[26] = {0};
        char next = 'a';
        for (char c : key) {
            if (c != ' ' && table[c - 'a'] == 0) {
                table[c - 'a'] = next++;
            }
        }
        string result = message;
        for (char& c : result) {
            if (c != ' ') c = table[c - 'a'];
        }
        return result;
    }
};
