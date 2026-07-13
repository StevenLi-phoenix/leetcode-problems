// @leetcode id=1233 questionId=1350 slug=remove-sub-folders-from-the-filesystem lang=cpp site=leetcode.com title="Remove Sub-Folders from the Filesystem"
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        for (auto& f : folder) {
            if (result.empty() ||
                !(f.size() > result.back().size() &&
                  f.compare(0, result.back().size(), result.back()) == 0 &&
                  f[result.back().size()] == '/')) {
                result.push_back(f);
            }
        }
        return result;
    }
};
