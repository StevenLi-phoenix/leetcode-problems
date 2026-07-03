// @leetcode id=1414 questionId=1515 slug=find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k lang=cpp site=leetcode.com title="Find the Minimum Number of Fibonacci Numbers Whose Sum Is K"
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<long long> fibs = {1, 1};
        while (fibs.back() <= k) {
            fibs.push_back(fibs[fibs.size() - 1] + fibs[fibs.size() - 2]);
        }

        int count = 0;
        long long remaining = k;
        int i = fibs.size() - 1;
        while (remaining > 0) {
            while (fibs[i] > remaining) --i;
            remaining -= fibs[i];
            ++count;
        }
        return count;
    }
};
