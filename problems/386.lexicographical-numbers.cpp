// @leetcode id=386 questionId=386 slug=lexicographical-numbers lang=cpp site=leetcode.com title="Lexicographical Numbers"
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        result.reserve(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            result.push_back(cur);
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                while (cur % 10 == 9 || cur + 1 > n) {
                    cur /= 10;
                }
                cur++;
            }
        }
        return result;
    }
};
