// @leetcode id=3019 questionId=3312 slug=number-of-changing-keys lang=cpp site=leetcode.com title="Number of Changing Keys"
class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        for (int i = 1; i < s.size(); i++) {
            if (tolower(s[i]) != tolower(s[i-1])) {
                count++;
            }
        }
        return count;
    }
};
