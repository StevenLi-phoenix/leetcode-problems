// @leetcode id=3751 questionId=4057 slug=total-waviness-of-numbers-in-range-i lang=cpp site=leetcode.com title="Total Waviness of Numbers in Range I"
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int n = num1; n <= num2; n++) {
            string s = to_string(n);
            int len = s.size();
            if (len < 3) continue;
            for (int i = 1; i < len - 1; i++) {
                int d = s[i] - '0';
                int l = s[i-1] - '0';
                int r = s[i+1] - '0';
                if ((d > l && d > r) || (d < l && d < r)) {
                    total++;
                }
            }
        }
        return total;
    }
};
