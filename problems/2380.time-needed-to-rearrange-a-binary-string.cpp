// @leetcode id=2380 questionId=2464 slug=time-needed-to-rearrange-a-binary-string lang=cpp site=leetcode.com title="Time Needed to Rearrange a Binary String"
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int seconds = 0;
        while (s.find("01") != string::npos) {
            string next = s;
            for (int i = 0; i + 1 < (int)s.size(); i++) {
                if (s[i] == '0' && s[i+1] == '1') {
                    next[i] = '1';
                    next[i+1] = '0';
                    i++; // skip next char since we swapped
                }
            }
            s = next;
            seconds++;
        }
        return seconds;
    }
};
