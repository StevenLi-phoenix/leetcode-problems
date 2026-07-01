// @leetcode id=3668 questionId=4008 slug=restore-finishing-order lang=cpp site=leetcode.com title="Restore Finishing Order"
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> friendSet(friends.begin(), friends.end());
        vector<int> result;
        for (int id : order) {
            if (friendSet.count(id)) result.push_back(id);
        }
        return result;
    }
};
