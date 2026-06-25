// @leetcode id=2455 questionId=2542 slug=average-value-of-even-numbers-that-are-divisible-by-three lang=cpp site=leetcode.com title="Average Value of Even Numbers That Are Divisible by Three"
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int count = 0;

        for (int num : nums) {
            if (num % 6 == 0) {
                sum += num;
                count++;
            }
        }

        if (count == 0) return 0;
        return sum / count;
    }
};
