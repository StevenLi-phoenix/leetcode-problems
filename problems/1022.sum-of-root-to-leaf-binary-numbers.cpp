// @leetcode id=1022 questionId=1079 slug=sum-of-root-to-leaf-binary-numbers lang=cpp site=leetcode.com title="Sum of Root To Leaf Binary Numbers"
class Solution {
public:
int sumRootToLeaf(TreeNode* root) {
int ans = 0;
function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int val) {
if (!node) return;
val = val * 2 + node->val;
if (!node->left && !node->right) {
ans += val;
return;
}
dfs(node->left, val);
dfs(node->right, val);
};
dfs(root, 0);
return ans;
}
};
