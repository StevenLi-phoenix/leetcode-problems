// @leetcode id=222 questionId=222 slug=count-complete-tree-nodes lang=cpp site=leetcode.com title="Count Complete Tree Nodes"
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        // Get left height (go left always)
        int lh = 0, rh = 0;
        TreeNode* node = root;
        while (node) { lh++; node = node->left; }
        node = root;
        while (node) { rh++; node = node->right; }
        
        // If heights equal, it's a perfect binary tree
        if (lh == rh) return (1 << lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
