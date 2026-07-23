// @leetcode id=3731 questionId=4107 slug=find-missing-elements lang=cpp site=leetcode.com title="Find Missing Elements"
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> present(nums.begin(), nums.end());
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());

        vector<int> result;
        for (int x = lo; x <= hi; x++) {
            if (!present.count(x)) result.push_back(x);
        }
        return result;
    }
};
