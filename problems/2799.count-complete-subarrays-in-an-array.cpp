// @leetcode id=2799 questionId=2856 slug=count-complete-subarrays-in-an-array lang=cpp site=leetcode.com title="Count Complete Subarrays in an Array"
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> allDistinct(nums.begin(), nums.end());
        int total = allDistinct.size();

        unordered_map<int, int> count;
        int left = 0;
        long long result = 0;

        for (int right = 0; right < n; right++) {
            count[nums[right]]++;
            while ((int)count.size() == total) {
                result += n - right;
                count[nums[left]]--;
                if (count[nums[left]] == 0) count.erase(nums[left]);
                left++;
            }
        }
        return (int)result;
    }
};
