// @leetcode id=2496 questionId=2589 slug=maximum-value-of-a-string-in-an-array lang=cpp site=leetcode.com title="Maximum Value of a String in an Array"
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int best = 0;
        for (const string& s : strs) {
            bool allDigits = all_of(s.begin(), s.end(), ::isdigit);
            int value = allDigits ? stoi(s) : (int)s.size();
            best = max(best, value);
        }
        return best;
    }
};
