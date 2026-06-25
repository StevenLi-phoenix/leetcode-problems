// @leetcode id=2404 questionId=2486 slug=most-frequent-even-element lang=cpp site=leetcode.com title="Most Frequent Even Element"
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            if (num % 2 == 0) {
                freq[num]++;
            }
        }

        if (freq.empty()) return -1;

        int result = -1;
        int maxCount = 0;

        for (auto& [num, count] : freq) {
            if (count > maxCount || (count == maxCount && num < result)) {
                result = num;
                maxCount = count;
            }
        }

        return result;
    }
};
