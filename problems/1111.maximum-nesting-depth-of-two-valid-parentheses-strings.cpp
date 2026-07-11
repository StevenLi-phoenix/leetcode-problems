// @leetcode id=1111 questionId=1208 slug=maximum-nesting-depth-of-two-valid-parentheses-strings lang=cpp site=leetcode.com title="Maximum Nesting Depth of Two Valid Parentheses Strings"
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // Splitting by depth parity halves the max depth each subsequence sees.
        vector<int> ans(seq.size());
        int depth = 0;
        for (int i = 0; i < (int)seq.size(); i++) {
            if (seq[i] == '(') {
                depth++;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                depth--;
            }
        }
        return ans;
    }
};
