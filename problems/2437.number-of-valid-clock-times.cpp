// @leetcode id=2437 questionId=2528 slug=number-of-valid-clock-times lang=cpp site=leetcode.com title="Number of Valid Clock Times"
class Solution {
public:
    int countTime(string time) {
        auto matches = [](const string& pattern, const string& value) {
            for (int i = 0; i < (int)pattern.size(); i++) {
                if (pattern[i] != '?' && pattern[i] != value[i]) return false;
            }
            return true;
        };

        int count = 0;
        for (int h = 0; h < 24; h++) {
            for (int m = 0; m < 60; m++) {
                char buf[6];
                snprintf(buf, sizeof(buf), "%02d:%02d", h, m);
                if (matches(time, string(buf))) count++;
            }
        }
        return count;
    }
};
