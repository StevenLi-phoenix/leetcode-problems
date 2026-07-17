// @leetcode id=768 questionId=779 slug=max-chunks-to-make-sorted-ii lang=cpp site=leetcode.com title="Max Chunks To Make Sorted II"
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> maxStack;

        for (int x : arr) {
            if (maxStack.empty() || x >= maxStack.back()) {
                maxStack.push_back(x);
            } else {
                int top = maxStack.back();
                while (!maxStack.empty() && maxStack.back() > x) maxStack.pop_back();
                maxStack.push_back(top);
            }
        }

        return maxStack.size();
    }
};
