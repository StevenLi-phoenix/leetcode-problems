// @leetcode id=1807 questionId=1934 slug=evaluate-the-bracket-pairs-of-a-string lang=cpp site=leetcode.com title="Evaluate the Bracket Pairs of a String"
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kv;
        for (auto& k : knowledge) kv[k[0]] = k[1];

        string result;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                int j = i + 1;
                while (s[j] != ')') j++;
                string key = s.substr(i + 1, j - i - 1);
                auto it = kv.find(key);
                result += (it != kv.end()) ? it->second : "?";
                i = j + 1;
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};
