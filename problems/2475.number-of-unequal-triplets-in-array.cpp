// @leetcode id=2475 questionId=2566 slug=number-of-unequal-triplets-in-array lang=cpp site=leetcode.com title="Number of Unequal Triplets in Array"
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        // Count frequency of each number
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        
        int n = nums.size();
        int result = 0;
        int left = 0; // elements processed so far (on the left)
        
        for (auto& [val, cnt] : freq) {
            int right = n - left - cnt;
            result += left * cnt * right;
            left += cnt;
        }
        return result;
    }
};
