// @leetcode id=3597 questionId=3905 slug=partition-string lang=cpp site=leetcode.com title="Partition String "
class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> result;
        string cur;
        for (char c : s) {
            cur.push_back(c);
            if (!seen.count(cur)) {
                seen.insert(cur);
                result.push_back(cur);
                cur.clear();
            }
        }
        return result;
    }
};
