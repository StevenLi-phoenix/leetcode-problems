// @leetcode id=1382 questionId=1285 slug=balance-a-binary-search-tree lang=cpp site=leetcode.com title="Balance a Binary Search Tree"
class Solution {
    public:
    vector<int> vals;
    void inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    vals.push_back(node->val);
    inorder(node->right);
    }
    TreeNode* build(int l, int r) {
    if (l > r) return nullptr;
    int m = (l + r) / 2;
    TreeNode* node = new TreeNode(vals[m]);
    node->left = build(l, m-1);
    node->right = build(m+1, r);
    return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
    inorder(root);
    return build(0, vals.size()-1);
    }
    };
