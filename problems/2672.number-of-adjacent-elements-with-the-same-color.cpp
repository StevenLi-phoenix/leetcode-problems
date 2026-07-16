// @leetcode id=2672 questionId=2779 slug=number-of-adjacent-elements-with-the-same-color lang=cpp site=leetcode.com title="Number of Adjacent Elements With the Same Color"
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> colors(n, 0);
        int count = 0;
        vector<int> result;
        result.reserve(queries.size());

        for (auto& q : queries) {
            int idx = q[0], color = q[1];

            if (idx > 0 && colors[idx - 1] != 0 && colors[idx - 1] == colors[idx]) count--;
            if (idx < n - 1 && colors[idx + 1] != 0 && colors[idx + 1] == colors[idx]) count--;

            colors[idx] = color;

            if (idx > 0 && colors[idx - 1] != 0 && colors[idx - 1] == colors[idx]) count++;
            if (idx < n - 1 && colors[idx + 1] != 0 && colors[idx + 1] == colors[idx]) count++;

            result.push_back(count);
        }
        return result;
    }
};
