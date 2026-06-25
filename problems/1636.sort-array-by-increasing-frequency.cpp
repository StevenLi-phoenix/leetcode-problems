// @leetcode id=1636 questionId=1741 slug=sort-array-by-increasing-frequency lang=cpp site=leetcode.com title="Sort Array by Increasing Frequency"
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b];
            }
            return a > b;
        });

        return nums;
    }
};
