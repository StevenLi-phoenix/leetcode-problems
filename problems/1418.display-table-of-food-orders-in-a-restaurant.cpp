// @leetcode id=1418 questionId=1533 slug=display-table-of-food-orders-in-a-restaurant lang=cpp site=leetcode.com title="Display Table of Food Orders in a Restaurant"
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foods;
        set<int> tables;
        map<int, map<string, int>> count;

        for (auto& o : orders) {
            int table = stoi(o[1]);
            string food = o[2];
            foods.insert(food);
            tables.insert(table);
            count[table][food]++;
        }

        vector<string> foodList(foods.begin(), foods.end());
        vector<vector<string>> result;

        vector<string> header;
        header.push_back("Table");
        for (auto& f : foodList) header.push_back(f);
        result.push_back(header);

        for (int table : tables) {
            vector<string> row;
            row.push_back(to_string(table));
            for (auto& f : foodList) {
                row.push_back(to_string(count[table][f]));
            }
            result.push_back(row);
        }
        return result;
    }
};
