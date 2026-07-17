// @leetcode id=2509 questionId=2597 slug=cycle-length-queries-in-a-tree lang=cpp site=leetcode.com title="Cycle Length Queries in a Tree"
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        for (auto& q : queries) {
            long long a = q[0], b = q[1];
            int steps = 0;
            while (a != b) {
                if (a > b) a /= 2;
                else b /= 2;
                steps++;
            }
            answer.push_back(steps + 1);
        }
        return answer;
    }
};
