// @leetcode id=2342 questionId=2473 slug=max-sum-of-a-pair-with-equal-sum-of-digits lang=cpp site=leetcode.com title="Max Sum of a Pair With Equal Sum of Digits"
class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x > 0) { s += x % 10; x /= 10; }
        return s;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> best;
        int result = -1;
        for (int x : nums) {
            int ds = digitSum(x);
            auto it = best.find(ds);
            if (it != best.end()) {
                result = max(result, it->second + x);
                if (x > it->second) it->second = x;
            } else {
                best[ds] = x;
            }
        }
        return result;
    }
};
