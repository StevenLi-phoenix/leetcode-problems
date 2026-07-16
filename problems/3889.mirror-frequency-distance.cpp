// @leetcode id=3889 questionId=4273 slug=mirror-frequency-distance lang=cpp site=leetcode.com title="Mirror Frequency Distance"
class Solution {
public:
    int mirrorFrequency(string s) {
        int freq[128] = {0};
        for (char c : s) freq[(int)c]++;

        long long total = 0;
        for (int i = 0; i < 13; i++) {
            char c = 'a' + i;
            char m = 'z' - i;
            if (freq[(int)c] > 0 || freq[(int)m] > 0) {
                total += abs(freq[(int)c] - freq[(int)m]);
            }
        }
        for (int i = 0; i < 5; i++) {
            char c = '0' + i;
            char m = '9' - i;
            if (freq[(int)c] > 0 || freq[(int)m] > 0) {
                total += abs(freq[(int)c] - freq[(int)m]);
            }
        }
        return (int)total;
    }
};
