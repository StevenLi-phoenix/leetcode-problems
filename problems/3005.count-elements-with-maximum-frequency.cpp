// @leetcode id=3005 questionId=3242 slug=count-elements-with-maximum-frequency lang=cpp site=leetcode.com title="Count Elements With Maximum Frequency"
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        int result = 0;
        for (auto& p : freq) {
            if (p.second == maxFreq) {
                result += maxFreq;
            }
        }

        return result;
    }
};
