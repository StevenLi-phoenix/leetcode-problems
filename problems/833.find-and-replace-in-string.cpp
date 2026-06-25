// @leetcode id=833 questionId=862 slug=find-and-replace-in-string lang=cpp site=leetcode.com title="Find And Replace in String"
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = indices.size();
        map<int, pair<string, string>> replacementMap;

        for (int i = 0; i < k; i++) {
            int idx = indices[i];
            if (idx + sources[i].length() <= s.length() &&
                s.substr(idx, sources[i].length()) == sources[i]) {
                replacementMap[idx] = {sources[i], targets[i]};
            }
        }

        for (auto it = replacementMap.rbegin(); it != replacementMap.rend(); ++it) {
            int idx = it->first;
            string source = it->second.first;
            string target = it->second.second;
            s.replace(idx, source.length(), target);
        }

        return s;
    }
};
