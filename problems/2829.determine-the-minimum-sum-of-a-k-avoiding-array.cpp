// @leetcode id=2829 questionId=2811 slug=determine-the-minimum-sum-of-a-k-avoiding-array lang=cpp site=leetcode.com title="Determine the Minimum Sum of a k-avoiding Array"
class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> chosen;
        int sum = 0;
        int candidate = 1;

        while ((int)chosen.size() < n) {
            if (!chosen.count(k - candidate)) {
                chosen.insert(candidate);
                sum += candidate;
            }
            ++candidate;
        }
        return sum;
    }
};
