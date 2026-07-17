// @leetcode id=2197 questionId=2307 slug=replace-non-coprime-numbers-in-array lang=cpp site=leetcode.com title="Replace Non-Coprime Numbers in Array"
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> stack;

        for (int x : nums) {
            long long cur = x;
            while (!stack.empty()) {
                long long g = std::__gcd(stack.back(), cur);
                if (g > 1) {
                    cur = stack.back() / g * cur;
                    stack.pop_back();
                } else {
                    break;
                }
            }
            stack.push_back(cur);
        }

        vector<int> result(stack.begin(), stack.end());
        return result;
    }
};
