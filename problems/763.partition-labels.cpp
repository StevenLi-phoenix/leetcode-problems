// @leetcode id=763 questionId=768 slug=partition-labels lang=cpp site=leetcode.com title="Partition Labels"
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastIdx[26];
        for (int i = 0; i < (int)s.size(); i++) lastIdx[s[i] - 'a'] = i;

        vector<int> result;
        int start = 0, end = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            end = max(end, lastIdx[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
