// @leetcode id=1441 questionId=1552 slug=build-an-array-with-stack-operations lang=cpp site=leetcode.com title="Build an Array With Stack Operations"
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int idx = 0;
        for (int num = 1; num <= n && idx < (int)target.size(); num++) {
            ops.push_back("Push");
            if (target[idx] == num) {
                idx++;
            } else {
                ops.push_back("Pop");
            }
        }
        return ops;
    }
};
