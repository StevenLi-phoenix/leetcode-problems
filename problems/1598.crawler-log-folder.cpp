// @leetcode id=1598 questionId=1720 slug=crawler-log-folder lang=cpp site=leetcode.com title="Crawler Log Folder"
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (const string& log : logs) {
            if (log == "../") {
                depth = max(0, depth - 1);
            } else if (log == "./") {
                // stay
            } else {
                depth++;
            }
        }
        return depth;
    }
};
