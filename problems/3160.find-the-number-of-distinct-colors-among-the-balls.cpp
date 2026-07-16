// @leetcode id=3160 questionId=3434 slug=find-the-number-of-distinct-colors-among-the-balls lang=cpp site=leetcode.com title="Find the Number of Distinct Colors Among the Balls"
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_map<int, int> colorCount;
        vector<int> result;
        result.reserve(queries.size());

        for (auto& q : queries) {
            int ball = q[0], color = q[1];
            auto it = ballColor.find(ball);
            if (it != ballColor.end()) {
                int oldColor = it->second;
                if (oldColor != color) {
                    if (--colorCount[oldColor] == 0) colorCount.erase(oldColor);
                    colorCount[color]++;
                    it->second = color;
                }
            } else {
                ballColor[ball] = color;
                colorCount[color]++;
            }
            result.push_back((int)colorCount.size());
        }
        return result;
    }
};
