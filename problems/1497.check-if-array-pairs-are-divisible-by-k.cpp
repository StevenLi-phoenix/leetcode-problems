// @leetcode id=1497 questionId=1620 slug=check-if-array-pairs-are-divisible-by-k lang=cpp site=leetcode.com title="Check If Array Pairs Are Divisible by k"
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for (int num : arr) {
            freq[((num % k) + k) % k]++;
        }
        // Elements with remainder 0 must pair among themselves
        if (freq[0] % 2 != 0) return false;
        // For each remainder r, count[r] must equal count[k-r]
        for (int r = 1; r <= k / 2; r++) {
            if (r == k - r) {
                // This happens when k is even and r == k/2
                if (freq[r] % 2 != 0) return false;
            } else {
                if (freq[r] != freq[k - r]) return false;
            }
        }
        return true;
    }
};
