// @leetcode id=1894 questionId=2006 slug=find-the-student-that-will-replace-the-chalk lang=cpp site=leetcode.com title="Find the Student that Will Replace the Chalk"
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for (int c : chalk) total += c;
        long long remaining = k % total;

        for (int i = 0; i < (int)chalk.size(); i++) {
            if (remaining < chalk[i]) return i;
            remaining -= chalk[i];
        }
        return 0;
    }
};
