// @leetcode id=2011 questionId=2137 slug=final-value-of-variable-after-performing-operations lang=cpp site=leetcode.com title="Final Value of Variable After Performing Operations"
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const string& op : operations) {
            x += (op[1] == '+') ? 1 : -1;
        }
        return x;
    }
};
