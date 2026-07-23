// @leetcode id=929 questionId=965 slug=unique-email-addresses lang=cpp site=leetcode.com title="Unique Email Addresses"
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;

        for (const string& email : emails) {
            int at = email.find('@');
            string local = email.substr(0, at);
            string domain = email.substr(at);

            string cleanLocal;
            for (char c : local) {
                if (c == '+') break;
                if (c == '.') continue;
                cleanLocal += c;
            }

            unique.insert(cleanLocal + domain);
        }

        return unique.size();
    }
};
