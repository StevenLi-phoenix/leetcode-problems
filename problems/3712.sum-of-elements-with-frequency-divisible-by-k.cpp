// @leetcode id=3712 questionId=4068 slug=sum-of-elements-with-frequency-divisible-by-k lang=cpp site=leetcode.com title="Sum of Elements With Frequency Divisible by K"
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int sum = 0;
        for (int x : nums) {
            if (freq[x] % k == 0) sum += x;
        }
        return sum;
    }
};
