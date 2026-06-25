// @leetcode id=99 questionId=99 slug=recover-binary-search-tree lang=cpp site=leetcode.com title="Recover Binary Search Tree"
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        
        // Morris inorder traversal to find swapped nodes
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            
            if (prev && prev->val > node->val) {
                if (!first) first = prev;
                second = node;
            }
            prev = node;
            
            inorder(node->right);
        };
        
        inorder(root);
        
        // Swap the values back
        swap(first->val, second->val);
    }
};
