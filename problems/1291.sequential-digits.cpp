// @leetcode id=1291 questionId=1212 slug=sequential-digits lang=cpp site=leetcode.com title="Sequential Digits"
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;
        for (int len = 2; len <= 9; len++) {
            for (int start = 0; start + len <= 9; start++) {
                int val = stoi(digits.substr(start, len));
                if (val >= low && val <= high) ans.push_back(val);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
