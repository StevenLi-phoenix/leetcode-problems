// @leetcode id=728 questionId=728 slug=self-dividing-numbers lang=cpp site=leetcode.com title="Self Dividing Numbers"
class Solution {
public:
    bool isSelfDividing(int num) {
        int x = num;
        while (x > 0) {
            int digit = x % 10;
            if (digit == 0 || num % digit != 0) return false;
            x /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) result.push_back(i);
        }
        return result;
    }
};
