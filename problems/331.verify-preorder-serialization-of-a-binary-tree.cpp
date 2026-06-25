// @leetcode id=331 questionId=331 slug=verify-preorder-serialization-of-a-binary-tree lang=cpp site=leetcode.com title="Verify Preorder Serialization of a Binary Tree"
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        int i = 0;
        int n = preorder.size();
        while (i < n) {
            if (slots == 0) return false;
            // Read current token
            int j = i;
            while (j < n && preorder[j] != ',') j++;
            string token = preorder.substr(i, j - i);
            i = j + 1; // skip comma
            if (token == "#") {
                slots--; // null consumes 1 slot
            } else {
                slots--; // consume 1 slot
                slots += 2; // add 2 children slots
            }
        }
        return slots == 0;
    }
};
