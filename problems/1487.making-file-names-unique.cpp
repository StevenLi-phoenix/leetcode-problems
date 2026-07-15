// @leetcode id=1487 questionId=1611 slug=making-file-names-unique lang=cpp site=leetcode.com title="Making File Names Unique"
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> nextSuffix;
        vector<string> result;

        for (const string& name : names) {
            if (!nextSuffix.count(name)) {
                result.push_back(name);
                nextSuffix[name] = 1;
            } else {
                int k = nextSuffix[name];
                string candidate = name + "(" + to_string(k) + ")";
                while (nextSuffix.count(candidate)) {
                    k++;
                    candidate = name + "(" + to_string(k) + ")";
                }
                result.push_back(candidate);
                nextSuffix[name] = k + 1;
                nextSuffix[candidate] = 1;
            }
        }
        return result;
    }
};
