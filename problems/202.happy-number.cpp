// @leetcode id=202 questionId=202 slug=happy-number lang=cpp site=leetcode.com title="Happy Number"
class Solution {
public:
    bool isHappy(int n) {
        auto next = [](int x) {
            int sum = 0;
            while (x > 0) {
                int d = x % 10;
                sum += d * d;
                x /= 10;
            }
            return sum;
        };

        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = next(n);
        }
        return n == 1;
    }
};
