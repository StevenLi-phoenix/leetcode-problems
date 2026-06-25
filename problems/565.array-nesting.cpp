// @leetcode id=565 questionId=565 slug=array-nesting lang=cpp site=leetcode.com title="Array Nesting"
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int len = 0;
                int cur = i;
                while (!visited[cur]) {
                    visited[cur] = true;
                    cur = nums[cur];
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
