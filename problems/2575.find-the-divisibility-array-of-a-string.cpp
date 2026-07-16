// @leetcode id=2575 questionId=2713 slug=find-the-divisibility-array-of-a-string lang=cpp site=leetcode.com title="Find the Divisibility Array of a String"
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> result;
        result.reserve(word.size());
        long long rem = 0;
        for (char c : word) {
            rem = (rem * 10 + (c - '0')) % m;
            result.push_back(rem == 0 ? 1 : 0);
        }
        return result;
    }
};
