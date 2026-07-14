// @leetcode id=1419 questionId=1534 slug=minimum-number-of-frogs-croaking lang=cpp site=leetcode.com title="Minimum Number of Frogs Croaking"
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string order = "croak";
        unordered_map<char, int> idx;
        for (int i = 0; i < 5; i++) idx[order[i]] = i;

        vector<int> count(5, 0);
        int active = 0, maxActive = 0;

        for (char c : croakOfFrogs) {
            int i = idx[c];
            if (i == 0) {
                count[0]++;
                active++;
                maxActive = max(maxActive, active);
            } else {
                if (count[i - 1] == 0) return -1;
                count[i - 1]--;
                count[i]++;
                if (i == 4) {
                    count[4]--;
                    active--;
                }
            }
        }

        if (active != 0) return -1;
        for (int i = 0; i < 4; i++) if (count[i] != 0) return -1;
        return maxActive;
    }
};
