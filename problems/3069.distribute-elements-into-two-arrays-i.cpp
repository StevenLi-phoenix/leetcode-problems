// @leetcode id=3069 questionId=3347 slug=distribute-elements-into-two-arrays-i lang=cpp site=leetcode.com title="Distribute Elements Into Two Arrays I"
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};

        for (int i = 2; i < (int)nums.size(); i++) {
            if (arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
