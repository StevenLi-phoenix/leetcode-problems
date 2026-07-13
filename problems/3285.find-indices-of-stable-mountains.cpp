// @leetcode id=3285 questionId=3582 slug=find-indices-of-stable-mountains lang=cpp site=leetcode.com title="Find Indices of Stable Mountains"
class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> result;
        for (int i = 1; i < (int)height.size(); i++) {
            if (height[i - 1] > threshold) result.push_back(i);
        }
        return result;
    }
};
