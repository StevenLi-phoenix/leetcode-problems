// @leetcode id=1948 questionId=2079 slug=delete-duplicate-folders-in-system lang=cpp site=leetcode.com title="Delete Duplicate Folders in System"
class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        struct TrieNode {
            map<string, TrieNode*> children;
            bool marked = false;
        };

        TrieNode* root = new TrieNode();
        for (auto& path : paths) {
            TrieNode* cur = root;
            for (auto& name : path) {
                if (!cur->children.count(name)) cur->children[name] = new TrieNode();
                cur = cur->children[name];
            }
        }

        unordered_map<string, vector<TrieNode*>> sigGroups;

        function<string(TrieNode*)> computeSig = [&](TrieNode* node) -> string {
            if (node->children.empty()) return "";
            string sig = "(";
            for (auto& [name, child] : node->children) {
                sig += name + computeSig(child) + ",";
            }
            sig += ")";
            sigGroups[sig].push_back(node);
            return sig;
        };
        computeSig(root);

        for (auto& [sig, nodes] : sigGroups) {
            if (nodes.size() >= 2) {
                for (TrieNode* node : nodes) node->marked = true;
            }
        }

        vector<vector<string>> result;
        vector<string> curPath;
        function<void(TrieNode*)> dfs = [&](TrieNode* node) {
            for (auto& [name, child] : node->children) {
                if (child->marked) continue;
                curPath.push_back(name);
                result.push_back(curPath);
                dfs(child);
                curPath.pop_back();
            }
        };
        dfs(root);

        return result;
    }
};
