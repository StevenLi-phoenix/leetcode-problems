// @leetcode id=919 questionId=955 slug=complete-binary-tree-inserter lang=cpp site=leetcode.com title="Complete Binary Tree Inserter"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* root;
    deque<TreeNode*> dq; // nodes that may have room for children
    
    CBTInserter(TreeNode* root) {
        this->root = root;
        // BFS to find nodes with open slots
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            // If node doesn't have both children, add to deque
            if (!node->left || !node->right) {
                dq.push_back(node);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        TreeNode* parent = dq.front();
        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
            dq.pop_front(); // parent is full now
        }
        dq.push_back(newNode); // new node has open slots
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
