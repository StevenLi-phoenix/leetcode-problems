// @leetcode id=3499 questionId=3805 slug=maximize-active-section-with-trade-i lang=cpp site=leetcode.com title="Maximize Active Section with Trade I"
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int n = t.size();

        vector<int> runLen;
        vector<char> runChar;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            runLen.push_back(j - i);
            runChar.push_back(t[i]);
            i = j;
        }

        int ones = count(s.begin(), s.end(), '1');
        int bestGain = 0;
        int m = runLen.size();
        for (int r = 1; r + 1 < m; r++) {
            if (runChar[r] != '1') continue;
            // interior 1-run (not the first or last run), flanked by 0-runs
            int gain = runLen[r - 1] + runLen[r + 1];
            bestGain = max(bestGain, gain);
        }
        return ones + bestGain;
    }
};
