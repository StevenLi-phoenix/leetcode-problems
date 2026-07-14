// @leetcode id=722 questionId=722 slug=remove-comments lang=cpp site=leetcode.com title="Remove Comments"
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        string current;
        bool inBlock = false;

        for (auto& line : source) {
            int i = 0;
            int n = line.size();
            while (i < n) {
                if (inBlock) {
                    if (i + 1 < n && line[i] == '*' && line[i + 1] == '/') {
                        inBlock = false;
                        i += 2;
                    } else {
                        i++;
                    }
                } else {
                    if (i + 1 < n && line[i] == '/' && line[i + 1] == '/') {
                        break; // rest of line is a line comment
                    } else if (i + 1 < n && line[i] == '/' && line[i + 1] == '*') {
                        inBlock = true;
                        i += 2;
                    } else {
                        current.push_back(line[i]);
                        i++;
                    }
                }
            }
            if (!inBlock && !current.empty()) {
                result.push_back(current);
                current.clear();
            }
        }
        return result;
    }
};
