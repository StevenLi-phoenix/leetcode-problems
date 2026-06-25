// @leetcode id=466 questionId=466 slug=count-the-repetitions lang=cpp site=leetcode.com title="Count The Repetitions"
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> s2Count(n1 + 1, 0);
        vector<int> s2Pos(n1 + 1, 0);

        int s2Idx = 0;

        for (int i = 1; i <= n1; i++) {
            for (char c : s1) {
                if (c == s2[s2Idx]) {
                    s2Idx++;
                    if (s2Idx == s2.length()) {
                        s2Idx = 0;
                        s2Count[i]++;
                    }
                }
            }

            s2Count[i] += s2Count[i - 1];
            s2Pos[i] = s2Idx;

            if (s2Pos[i] == s2Pos[i - 1] && i > 1) {
                int cycleLen = i - 1;
                int cycleCount = s2Count[i] - s2Count[i - cycleLen];
                int remaining = n1 - i;
                int fullCycles = remaining / cycleLen;

                s2Count[n1] = s2Count[i] + fullCycles * cycleCount;

                int lastCycle = remaining % cycleLen;
                s2Count[n1] += s2Count[i - cycleLen + lastCycle] - s2Count[i - cycleLen];

                return s2Count[n1] / n2;
            }
        }

        return s2Count[n1] / n2;
    }
};
