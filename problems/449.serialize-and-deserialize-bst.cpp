// @leetcode id=449 questionId=449 slug=serialize-and-deserialize-bst lang=cpp site=leetcode.com title="Serialize and Deserialize BST"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        preorder(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> values;
        istringstream iss(data);
        int v;
        while (iss >> v) values.push_back(v);
        int idx = 0;
        return build(values, idx, INT_MIN, INT_MAX);
    }

private:
    void preorder(TreeNode* node, string& result) {
        if (!node) return;
        if (!result.empty()) result += ' ';
        result += to_string(node->val);
        preorder(node->left, result);
        preorder(node->right, result);
    }

    TreeNode* build(vector<int>& values, int& idx, int lo, int hi) {
        if (idx >= (int)values.size() || values[idx] < lo || values[idx] > hi) return nullptr;
        int val = values[idx++];
        TreeNode* node = new TreeNode(val);
        node->left = build(values, idx, lo, val);
        node->right = build(values, idx, val, hi);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
