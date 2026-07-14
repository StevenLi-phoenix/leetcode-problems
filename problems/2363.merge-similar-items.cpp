// @leetcode id=2363 questionId=2447 slug=merge-similar-items lang=cpp site=leetcode.com title="Merge Similar Items"
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> weightByValue;
        for (auto& it : items1) weightByValue[it[0]] += it[1];
        for (auto& it : items2) weightByValue[it[0]] += it[1];

        vector<vector<int>> result;
        for (auto& [v, w] : weightByValue) result.push_back({v, w});
        return result;
    }
};
