// @leetcode id=739 questionId=739 slug=daily-temperatures lang=cpp site=leetcode.com title="Daily Temperatures"
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        vector<int> stack;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && temperatures[stack.back()] < temperatures[i]) {
                int idx = stack.back(); stack.pop_back();
                result[idx] = i - idx;
            }
            stack.push_back(i);
        }
        return result;
    }
};
