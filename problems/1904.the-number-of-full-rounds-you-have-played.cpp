// @leetcode id=1904 questionId=2033 slug=the-number-of-full-rounds-you-have-played lang=cpp site=leetcode.com title="The Number of Full Rounds You Have Played"
class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int loginMin = stoi(loginTime.substr(0,2)) * 60 + stoi(loginTime.substr(3,2));
        int logoutMin = stoi(logoutTime.substr(0,2)) * 60 + stoi(logoutTime.substr(3,2));
        if (logoutMin < loginMin) logoutMin += 24 * 60;
        // Round login up to next 15-min boundary
        // Round logout down to previous 15-min boundary
        int start = (loginMin + 14) / 15;
        int end = logoutMin / 15;
        return max(0, end - start);
    }
};
