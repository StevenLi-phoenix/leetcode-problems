// @leetcode id=179 questionId=179 slug=largest-number lang=cpp site=leetcode.com title="Largest Number"
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int n : nums) strs.push_back(to_string(n));

        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        if (strs[0] == "0") return "0";

        string result;
        for (auto& s : strs) result += s;
        return result;
    }
};
