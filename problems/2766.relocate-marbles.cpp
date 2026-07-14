// @leetcode id=2766 questionId=2834 slug=relocate-marbles lang=cpp site=leetcode.com title="Relocate Marbles"
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> positions(nums.begin(), nums.end());
        for (int i = 0; i < (int)moveFrom.size(); i++) {
            positions.erase(moveFrom[i]);
            positions.insert(moveTo[i]);
        }
        return vector<int>(positions.begin(), positions.end());
    }
};
