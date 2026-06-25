// @leetcode id=2248 questionId=2331 slug=intersection-of-multiple-arrays lang=cpp site=leetcode.com title="Intersection of Multiple Arrays"
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> freq;

        for (auto& arr : nums) {
            for (int num : arr) {
                freq[num]++;
            }
        }

        vector<int> result;
        int n = nums.size();

        for (auto& [num, count] : freq) {
            if (count == n) {
                result.push_back(num);
            }
        }

        return result;
    }
};
