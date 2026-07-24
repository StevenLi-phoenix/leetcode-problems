// @leetcode id=3270 questionId=3568 slug=find-the-key-of-the-numbers lang=cpp site=leetcode.com title="Find the Key of the Numbers"
class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        char buf1[5], buf2[5], buf3[5];
        snprintf(buf1, sizeof(buf1), "%04d", num1);
        snprintf(buf2, sizeof(buf2), "%04d", num2);
        snprintf(buf3, sizeof(buf3), "%04d", num3);

        int key = 0;
        for (int i = 0; i < 4; i++) {
            int d = min({buf1[i] - '0', buf2[i] - '0', buf3[i] - '0'});
            key = key * 10 + d;
        }
        return key;
    }
};
