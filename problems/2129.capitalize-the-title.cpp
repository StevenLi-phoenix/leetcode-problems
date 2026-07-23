// @leetcode id=2129 questionId=2235 slug=capitalize-the-title lang=cpp site=leetcode.com title="Capitalize the Title"
class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string word, result;
        while (ss >> word) {
            for (char& c : word) c = tolower(c);
            if (word.size() > 2) word[0] = toupper(word[0]);
            if (!result.empty()) result += " ";
            result += word;
        }
        return result;
    }
};
