// @leetcode id=1663 questionId=1782 slug=smallest-string-with-a-given-numeric-value lang=cpp site=leetcode.com title="Smallest String With A Given Numeric Value"
class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 'a');
        k -= n;
        for (int i = n - 1; i >= 0 && k > 0; i--) {
            int add = min(k, 25);
            result[i] = 'a' + add;
            k -= add;
        }
        return result;
    }
};
