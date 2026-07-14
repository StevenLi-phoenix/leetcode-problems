// @leetcode id=1881 questionId=2011 slug=maximum-value-after-insertion lang=cpp site=leetcode.com title="Maximum Value after Insertion"
class Solution {
public:
    string maxValue(string n, int x) {
        bool negative = n[0] == '-';
        char xc = '0' + x;
        int start = negative ? 1 : 0;

        for (int i = start; i < (int)n.size(); i++) {
            bool shouldInsert = negative ? (n[i] > xc) : (n[i] < xc);
            if (shouldInsert) {
                return n.substr(0, i) + xc + n.substr(i);
            }
        }
        return n + xc;
    }
};
