// @leetcode id=1925 questionId=2037 slug=count-square-sum-triples lang=cpp site=leetcode.com title="Count Square Sum Triples"
class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int cSquared = a * a + b * b;
                int c = (int)sqrt((double)cSquared);
                if (c <= n && c * c == cSquared) count++;
            }
        }
        return count;
    }
};
