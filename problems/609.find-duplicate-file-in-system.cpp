// @leetcode id=609 questionId=609 slug=find-duplicate-file-in-system lang=cpp site=leetcode.com title="Find Duplicate File in System"
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentToFiles;

        for (const string& line : paths) {
            istringstream iss(line);
            string dir;
            iss >> dir;
            string token;
            while (iss >> token) {
                size_t paren = token.find('(');
                string filename = token.substr(0, paren);
                string content = token.substr(paren + 1, token.size() - paren - 2);
                contentToFiles[content].push_back(dir + "/" + filename);
            }
        }

        vector<vector<string>> result;
        for (auto& [content, files] : contentToFiles) {
            if (files.size() > 1) result.push_back(files);
        }
        return result;
    }
};
