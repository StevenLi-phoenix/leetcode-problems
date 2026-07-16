// @leetcode id=1769 questionId=1895 slug=minimum-number-of-operations-to-move-all-balls-to-each-box lang=cpp site=leetcode.com title="Minimum Number of Operations to Move All Balls to Each Box"
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        int count = 0, ops = 0;
        for (int i = 0; i < n; i++) {
            ans[i] += ops;
            count += boxes[i] - '0';
            if (i + 1 < n) ops += count;
        }

        count = 0; ops = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += ops;
            count += boxes[i] - '0';
            if (i - 1 >= 0) ops += count;
        }
        return ans;
    }
};
