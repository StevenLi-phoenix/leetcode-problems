// @leetcode id=1946 questionId=2077 slug=largest-number-after-mutating-substring lang=cpp site=leetcode.com title="Largest Number After Mutating Substring"
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        string result = num;
        bool started = false;
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            if (change[d] > d) {
                result[i] = '0' + change[d];
                started = true;
            } else if (change[d] < d) {
                if (started) break;
            }
        }
        return result;
    }
};
