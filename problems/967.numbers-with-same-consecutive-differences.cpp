// @leetcode id=967 questionId=1007 slug=numbers-with-same-consecutive-differences lang=cpp site=leetcode.com title="Numbers With Same Consecutive Differences"
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> cur;
        for (int d = 1; d <= 9; d++) cur.push_back(d);

        for (int step = 1; step < n; step++) {
            vector<int> next;
            for (int num : cur) {
                int last = num % 10;
                if (last + k <= 9) next.push_back(num * 10 + last + k);
                if (k != 0 && last - k >= 0) next.push_back(num * 10 + last - k);
            }
            cur = next;
        }
        return cur;
    }
};
