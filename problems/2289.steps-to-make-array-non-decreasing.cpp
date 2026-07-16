// @leetcode id=2289 questionId=2374 slug=steps-to-make-array-non-decreasing lang=cpp site=leetcode.com title="Steps to Make Array Non-decreasing"
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<pair<int, int>> stk; // value, removal step
        int answer = 0;

        for (int num : nums) {
            int curStep = 0;
            while (!stk.empty() && stk.back().first <= num) {
                curStep = max(curStep, stk.back().second);
                stk.pop_back();
            }
            if (!stk.empty()) {
                curStep++;
            } else {
                curStep = 0;
            }
            stk.push_back({num, curStep});
            answer = max(answer, curStep);
        }
        return answer;
    }
};
