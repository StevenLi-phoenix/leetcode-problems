// @leetcode id=3295 questionId=3541 slug=report-spam-message lang=cpp site=leetcode.com title="Report Spam Message"
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> banned(bannedWords.begin(), bannedWords.end());
        int count = 0;
        for (auto& w : message) {
            if (banned.count(w)) {
                count++;
                if (count >= 2) return true;
            }
        }
        return false;
    }
};
