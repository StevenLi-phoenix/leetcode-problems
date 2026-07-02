// @leetcode id=3582 questionId=3893 slug=generate-tag-for-video-caption lang=cpp site=leetcode.com title="Generate Tag for Video Caption"
class Solution {
public:
    string generateTag(string caption) {
        istringstream iss(caption);
        vector<string> words;
        string word;
        while (iss >> word) words.push_back(word);

        string tag = "#";
        for (int i = 0; i < (int)words.size(); ++i) {
            for (int j = 0; j < (int)words[i].size(); ++j) {
                char c = tolower(words[i][j]);
                if (i > 0 && j == 0) c = toupper(c);
                tag += c;
            }
        }

        if (tag.size() > 100) tag = tag.substr(0, 100);
        return tag;
    }
};
