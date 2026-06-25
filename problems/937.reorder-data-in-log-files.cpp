// @leetcode id=937 questionId=974 slug=reorder-data-in-log-files lang=cpp site=leetcode.com title="Reorder Data in Log Files"
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters, digits;

        for (const string& log : logs) {
            size_t space = log.find(' ');
            char type = log[space + 1];

            if (isdigit(type)) {
                digits.push_back(log);
            } else {
                letters.push_back(log);
            }
        }

        sort(letters.begin(), letters.end(), [](const string& a, const string& b) {
            size_t space_a = a.find(' ');
            size_t space_b = b.find(' ');
            string content_a = a.substr(space_a + 1);
            string content_b = b.substr(space_b + 1);

            if (content_a != content_b) {
                return content_a < content_b;
            }
            return a.substr(0, space_a) < b.substr(0, space_b);
        });

        letters.insert(letters.end(), digits.begin(), digits.end());
        return letters;
    }
};
