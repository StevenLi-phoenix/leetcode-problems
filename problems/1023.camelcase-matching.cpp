// @leetcode id=1023 questionId=1080 slug=camelcase-matching lang=cpp site=leetcode.com title="Camelcase Matching"
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (auto& q : queries) ans.push_back(matches(q, pattern));
        return ans;
    }

private:
    bool matches(const string& q, const string& pattern) {
        int j = 0;
        for (char c : q) {
            if (j < (int)pattern.size() && pattern[j] == c) {
                ++j;
            } else if (isupper(c)) {
                return false;
            }
        }
        return j == (int)pattern.size();
    }
};
