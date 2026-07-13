// @leetcode id=1248 questionId=1370 slug=count-number-of-nice-subarrays lang=cpp site=leetcode.com title="Count Number of Nice Subarrays"
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int oddCount = 0, result = 0;
        for (int v : nums) {
            if (v % 2 == 1) oddCount++;
            result += count[oddCount - k];
            count[oddCount]++;
        }
        return result;
    }
};
