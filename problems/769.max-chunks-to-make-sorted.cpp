// @leetcode id=769 questionId=780 slug=max-chunks-to-make-sorted lang=cpp site=leetcode.com title="Max Chunks To Make Sorted"
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, maxSoFar = -1;
        for (int i = 0; i < (int)arr.size(); i++) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i) chunks++;
        }
        return chunks;
    }
};
