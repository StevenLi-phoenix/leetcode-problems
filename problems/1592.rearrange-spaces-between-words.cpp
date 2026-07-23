// @leetcode id=1592 questionId=1714 slug=rearrange-spaces-between-words lang=cpp site=leetcode.com title="Rearrange Spaces Between Words"
class Solution {
public:
    string reorderSpaces(string text) {
        int totalSpaces = 0;
        for (char c : text) {
            if (c == ' ') totalSpaces++;
        }

        stringstream ss(text);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);

        int gaps = (int)words.size() - 1;
        int spacesBetween = gaps > 0 ? totalSpaces / gaps : 0;
        int extraSpaces = gaps > 0 ? totalSpaces % gaps : totalSpaces;

        string result;
        for (int i = 0; i < (int)words.size(); i++) {
            result += words[i];
            if (i != (int)words.size() - 1) {
                result += string(spacesBetween, ' ');
            }
        }
        result += string(extraSpaces, ' ');
        return result;
    }
};
