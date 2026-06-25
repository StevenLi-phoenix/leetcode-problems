// @leetcode id=140 questionId=140 slug=word-break-ii lang=cpp site=leetcode.com title="Word Break II"
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        
        function<vector<string>(int)> dfs = [&](int start) -> vector<string> {
            if (memo.count(start)) return memo[start];
            vector<string> result;
            if (start == s.size()) {
                result.push_back("");
                return result;
            }
            for (int end = start + 1; end <= (int)s.size(); end++) {
                string word = s.substr(start, end - start);
                if (dict.count(word)) {
                    vector<string> rest = dfs(end);
                    for (const string& r : rest) {
                        result.push_back(word + (r.empty() ? "" : " " + r));
                    }
                }
            }
            memo[start] = result;
            return result;
        };
        
        return dfs(0);
    }
};
