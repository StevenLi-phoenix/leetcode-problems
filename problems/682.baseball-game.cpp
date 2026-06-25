// @leetcode id=682 questionId=682 slug=baseball-game lang=cpp site=leetcode.com title="Baseball Game"
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        for (const string& op : ops) {
            if (op == "+") {
                int n = record.size();
                record.push_back(record[n-1] + record[n-2]);
            } else if (op == "D") {
                record.push_back(2 * record.back());
            } else if (op == "C") {
                record.pop_back();
            } else {
                record.push_back(stoi(op));
            }
        }
        int sum = 0;
        for (int x : record) sum += x;
        return sum;
    }
};
