// @leetcode id=3591 questionId=3914 slug=check-if-any-element-has-prime-frequency lang=cpp site=leetcode.com title="Check if Any Element Has Prime Frequency"
class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) ++freq[x];

        auto isPrime = [](int n) {
            if (n < 2) return false;
            for (int i = 2; (long long)i * i <= n; ++i) {
                if (n % i == 0) return false;
            }
            return true;
        };

        for (auto& [val, count] : freq) {
            if (isPrime(count)) return true;
        }
        return false;
    }
};
