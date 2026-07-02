// @leetcode id=297 questionId=297 slug=serialize-and-deserialize-binary-tree lang=cpp site=leetcode.com title="Serialize and Deserialize Binary Tree"
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
        string out;
        serializeHelper(root, out);
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }

private:
    void serializeHelper(TreeNode* node, string& out) {
        if (!node) {
            out += "#,";
            return;
        }
        out += to_string(node->val) + ",";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    TreeNode* deserializeHelper(const string& data, int& pos) {
        int comma = data.find(',', pos);
        string token = data.substr(pos, comma - pos);
        pos = comma + 1;
        if (token == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeHelper(data, pos);
        node->right = deserializeHelper(data, pos);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
