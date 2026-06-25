// @leetcode id=2110 questionId=2233 slug=number-of-smooth-descent-periods-of-a-stock lang=cpp site=leetcode.com title="Number of Smooth Descent Periods of a Stock"
#include <vector>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long streak = 0;

        for (int i = 0; i < (int)prices.size(); ++i) {
            if (i > 0 && prices[i - 1] - prices[i] == 1) {
                ++streak;
            } else {
                streak = 1;
            }
            ans += streak;
        }
        return ans;
    }
};
