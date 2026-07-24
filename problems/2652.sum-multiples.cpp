// @leetcode id=2652 questionId=2752 slug=sum-multiples lang=cpp site=leetcode.com title="Sum Multiples"
class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) sum += i;
        }
        return sum;
    }
};
