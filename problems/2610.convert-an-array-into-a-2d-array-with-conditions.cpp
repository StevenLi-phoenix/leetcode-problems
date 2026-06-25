// @leetcode id=2610 questionId=2724 slug=convert-an-array-into-a-2d-array-with-conditions lang=cpp site=leetcode.com title="Convert an Array Into a 2D Array With Conditions"
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnt;
        vector<vector<int>> res;
        
        for (int x : nums) {
            int freq = cnt[x]++;
            if (freq >= (int)res.size()) {
                res.push_back({});
            }
            res[freq].push_back(x);
        }
        
        return res;
    }
};
