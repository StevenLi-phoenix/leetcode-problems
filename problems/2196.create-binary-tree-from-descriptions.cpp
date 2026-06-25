// @leetcode id=2196 questionId=2306 slug=create-binary-tree-from-descriptions lang=cpp site=leetcode.com title="Create Binary Tree From Descriptions"
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        for (auto& desc : descriptions) {
            int parent = desc[0], child = desc[1], isLeft = desc[2];
            
            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }
            
            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
            
            children.insert(child);
        }
        
        for (auto& [val, node] : nodes) {
            if (children.find(val) == children.end()) {
                return node;
            }
        }
        
        return nullptr;
    }
};
