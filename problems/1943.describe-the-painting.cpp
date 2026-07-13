// @leetcode id=1943 questionId=2055 slug=describe-the-painting lang=cpp site=leetcode.com title="Describe the Painting"
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> diff;
        for (auto& s : segments) {
            diff[s[0]] += s[2];
            diff[s[1]] -= s[2];
        }

        vector<vector<long long>> result;
        long long curSum = 0;
        int prevPos = -1;
        for (auto& [pos, delta] : diff) {
            if (prevPos != -1 && curSum > 0) {
                result.push_back({prevPos, pos, curSum});
            }
            curSum += delta;
            prevPos = pos;
        }
        return result;
    }
};
