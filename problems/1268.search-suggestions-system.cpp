// @leetcode id=1268 questionId=1397 slug=search-suggestions-system lang=cpp site=leetcode.com title="Search Suggestions System"
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        string prefix;
        for (char c : searchWord) {
            prefix += c;
            auto it = lower_bound(products.begin(), products.end(), prefix);
            vector<string> suggestions;
            for (int cnt = 0; cnt < 3 && it != products.end() && it->compare(0, prefix.size(), prefix) == 0; cnt++, ++it) {
                suggestions.push_back(*it);
            }
            result.push_back(suggestions);
        }
        return result;
    }
};
