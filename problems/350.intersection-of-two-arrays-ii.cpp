// @leetcode id=350 questionId=350 slug=intersection-of-two-arrays-ii lang=cpp site=leetcode.com title="Intersection of Two Arrays II"
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        for (int x : nums1) count[x]++;

        vector<int> result;
        for (int x : nums2) {
            auto it = count.find(x);
            if (it != count.end() && it->second > 0) {
                result.push_back(x);
                it->second--;
            }
        }
        return result;
    }
};
