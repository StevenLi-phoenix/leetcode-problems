// @leetcode id=1282 questionId=1407 slug=group-the-people-given-the-group-size-they-belong-to lang=cpp site=leetcode.com title="Group the People Given the Group Size They Belong To"
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> result;
        
        for (int i = 0; i < (int)groupSizes.size(); i++) {
            int sz = groupSizes[i];
            mp[sz].push_back(i);
            if ((int)mp[sz].size() == sz) {
                result.push_back(mp[sz]);
                mp[sz].clear();
            }
        }
        
        return result;
    }
};
