// @leetcode id=2138 questionId=2260 slug=divide-a-string-into-groups-of-size-k lang=cpp site=leetcode.com title="Divide a String Into Groups of Size k"
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        while (s.size() % k != 0) s += fill;

        vector<string> groups;
        for (int i = 0; i < (int)s.size(); i += k) {
            groups.push_back(s.substr(i, k));
        }
        return groups;
    }
};
