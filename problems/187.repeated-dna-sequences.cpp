// @leetcode id=187 questionId=187 slug=repeated-dna-sequences lang=cpp site=leetcode.com title="Repeated DNA Sequences"
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        vector<string> result;
        int n = s.size();
        for (int i = 0; i + 10 <= n; i++) {
            string sub = s.substr(i, 10);
            if (++count[sub] == 2) result.push_back(sub);
        }
        return result;
    }
};
