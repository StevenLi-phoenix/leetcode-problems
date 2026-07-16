// @leetcode id=3159 questionId=3420 slug=find-occurrences-of-an-element-in-an-array lang=cpp site=leetcode.com title="Find Occurrences of an Element in an Array"
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indices;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == x) indices.push_back(i);
        }

        vector<int> result;
        for (int q : queries) {
            if (q > (int)indices.size()) result.push_back(-1);
            else result.push_back(indices[q - 1]);
        }
        return result;
    }
};
