// @leetcode id=3980 questionId=4334 slug=minimum-operations-to-transform-binary-string lang=cpp site=leetcode.com title="Minimum Operations to Transform Binary String"
class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int a = 0, pairs = 0, unmatched = 0;
        bool pending = false;

        for (int i = 0; i < n; i++) {
            bool isA = (s1[i] == '0' && s2[i] == '1');
            bool isB = (s1[i] == '1' && s2[i] == '0');
            if (isA) a++;

            if (isB) {
                if (pending) {
                    pairs++;
                    pending = false;
                } else {
                    pending = true;
                }
            } else {
                if (pending) unmatched++;
                pending = false;
            }
        }
        if (pending) unmatched++;

        if (unmatched > 0 && n == 1) return -1;

        return a + pairs + 2 * unmatched;
    }
};
