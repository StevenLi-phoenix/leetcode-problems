// @leetcode id=984 questionId=1026 slug=string-without-aaa-or-bbb lang=cpp site=leetcode.com title="String Without AAA or BBB"
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string result;
        while (a > 0 || b > 0) {
            int n = result.size();
            bool lastTwoA = n >= 2 && result[n - 1] == 'a' && result[n - 2] == 'a';
            bool lastTwoB = n >= 2 && result[n - 1] == 'b' && result[n - 2] == 'b';

            if ((a >= b && !lastTwoA) || lastTwoB) {
                result += 'a';
                a--;
            } else {
                result += 'b';
                b--;
            }
        }
        return result;
    }
};
