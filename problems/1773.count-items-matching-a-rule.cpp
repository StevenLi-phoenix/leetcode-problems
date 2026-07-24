// @leetcode id=1773 questionId=1899 slug=count-items-matching-a-rule lang=cpp site=leetcode.com title="Count Items Matching a Rule"
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx = (ruleKey == "type") ? 0 : (ruleKey == "color") ? 1 : 2;
        int count = 0;
        for (auto& item : items) {
            if (item[idx] == ruleValue) count++;
        }
        return count;
    }
};
